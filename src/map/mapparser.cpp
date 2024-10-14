#include "mapparser.h"
#include "SDL.h"
using std::vector;

bool MapParser::Load(string mapname, string source)
{
    std::cout << "Loading TMX map file... " << mapname << " " << source << std::endl;
    //validate if the map source spritesheet exists and can be opened
    if (!ParseMapFromFile(mapname, source)){

        std::cout << "Map Parser failed to load TMX map file: " << mapname << " , from source: " << source << std::endl;
        return false;
    }
    std::cout << "Loaded TMX map file successfully" << std::endl;
    return true;
}

bool MapParser::ParseMapFromFile(string id, string source)
{
    //validate if the xml file exists and can be opened
    TiXmlDocument xml;
    xml.LoadFile(source);
    if (xml.Error()) {
        return false;
    }

    //set up some variables to store the data coming from the map
    TiXmlElement* root = xml.RootElement(); //this is the <map> element in the map file
    int rows, cols = 0;
    int tilesize = 0;
    
    //extract the data from the map file from the <map> element
    root->Attribute("width", &cols);
    root->Attribute("height", &rows);
    root->Attribute("tilewidth", &tilesize);

    //parse the tilesets from the map file
    TileArray tilesets;
    for (TiXmlElement* e=root->FirstChildElement(); e!=nullptr; e=e->NextSiblingElement())
    {
        //loop found <tileset> element in the map file
        if (e->Value() == string("tileset")){
            tilesets.push_back(ParseTileset(e));
        }
    }

    //parse the layers from the map file
    GameMap* gamemap = new GameMap();
    for (TiXmlElement* e=root->FirstChildElement(); e!=nullptr; e=e->NextSiblingElement())
    {
        //loop found <layer> element in the map file
        if (e->Value() == string("layer")){
            TileLayer* tileLayer = ParseTileLayer(e,tilesets,tilesize,rows,cols);
            gamemap->m_mapLayers.push_back(tileLayer);
        }
    }

    m_mapdict[id] = gamemap;
    return true;
}

Tileset MapParser::ParseTileset(TiXmlElement *xmlTileset)
{
    Tileset tileset; //create empty tileset

    //extract the data from the map file
    tileset.name = xmlTileset->Attribute("name");          
    xmlTileset->Attribute("firstgid", &tileset.firstid);   
    xmlTileset->Attribute("tilewidth", &tileset.tilesize);  
    xmlTileset->Attribute("tilecount", &tileset.tilecount);
    xmlTileset->Attribute("columns", &tileset.columns); 

    //data that can be calculated
    tileset.rows = tileset.tilecount / tileset.columns;
    tileset.lastid = (tileset.firstid + tileset.tilecount) - 1;

    //load tileset spritesheet from the source file
    TiXmlElement* image = xmlTileset->FirstChildElement(); //get the first element of the <tileset> element which is the <image> element
    tileset.source = image->Attribute("source");

    return tileset;
}

TileLayer *MapParser::ParseTileLayer(TiXmlElement *xmlLayer, TileArray tilesets, int tilesize, int rows, int columns)
{
    TiXmlElement* data;

    //get the first element of the layer element, which is the <data> element containing the map matrix
    for(TiXmlElement* e = xmlLayer->FirstChildElement(); e!= nullptr; e=e->NextSiblingElement()){
        
        //check if the element is in fact the data element
        if (e->Value() == string("data")){

            //set our data, to the data element in the map file
            data = e;
            break;
        }
    }

    //get matrix from the data element in the map file
    string matrix(data->GetText());
    std::istringstream iss(matrix);
    string id;

    //create a 2d array/vector to store the matrix
    TileMap tilemap(rows,vector<int>(columns, 0));

    //For each row in the matrix
    for (int row = 0; row < rows; row++){

        //For each column in the matrix
        for (int col = 0; col < columns; col++){

            //get each line in the stream with the corresponding id, and split at each comma
            getline(iss,id,',');

            //insert our line into the tilemap 2d array
            std::stringstream convertor(id);
            convertor >> tilemap[row][col];

            //check if there was something wrong when writing to the file stream
            if(!iss.good()) break;
        }
    }

    //create a new tile layer with all the parsed data from the map file
    return (new TileLayer(tilesize, rows, columns, tilemap, tilesets));
}

bool MapParser::Clean()
{
    map<string, GameMap*>::iterator it;
    for(it = m_mapdict.begin(); it != m_mapdict.end(); it++){
        it->second = nullptr;
    }
    m_mapdict.clear();
    return false;
}