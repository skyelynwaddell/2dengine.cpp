#include "tilelayer.h"
#include "texture_manager.h"

#define SPRITESHEET_FILETYPE ".png"

TileLayer::TileLayer(int tilesize, int rows, int columns, TileMap tilemap, TileArray tilesets)
: m_tilesize(tilesize), m_rows(rows), m_columns(columns), m_tilemap(tilemap), m_tilesets(tilesets)
{
    m_tilesize = tilesize;
    std::cout << "tilesize: " << m_tilesize << std::endl;
    std::cout << "rows: " << m_rows << std::endl;
    std::cout << "columns: " << m_columns << std::endl;


    //Preload all the spritesheet images
    for (unsigned int tileset=0; tileset < m_tilesets.size(); tileset++)
    {

        string _name = m_tilesets[tileset].name;
        string _src = "assets/tilesets/" + _name + SPRITESHEET_FILETYPE;

        std::cout << "Loading spritesheet... " << _name << " : " << _src << std::endl; 
        TextureManager::GetInstance()->Load(_name, _src);
        std::cout << "Spritesheet loaded successfully" << std::endl;
    } 
}

void TileLayer::Draw()
{
    int index = 0; //defines the tileset used 
    bool found = false;

    //for all Rows in the tilelayer
    for (unsigned int row=0; row < m_rows; row++)
    {
        //for all Columns in the tilelayer
        for (unsigned int col=0; col < m_columns; col++)
        {
            //each number in the matrix represents a tile id.
            int tileID = m_tilemap[row][col];

            //make sure the tile id isnt 0 because that means its an empty tile
            if (tileID == 0) continue; //if it is stop the current iteration here, and go to the next iteration in the loop

            //if we have more than one tileset, it changes the tile_id's to start with the index used above, so we only have to do this if we have multiple tilesets in the same map
            if(m_tilesets.size() > 1) 
            {
                //loop through each tile in the matrix (id's start at 1 in the map file)
                for (unsigned int tile=0; tile<m_tilesets.size(); tile++){

                    //check if the tile id is not the first, or last tile in the map
                    if (tileID > m_tilesets[tile].firstid && tileID < m_tilesets[tile].lastid){
                        tileID = tileID + m_tilesets[tile].tilecount - m_tilesets[tile].lastid;
                        index = tile;

                        found = true;
                        break;
                    }
                }
            }

            //check if there was no tile found
            if (found == false) continue;

            std::cout << index << std::endl;

            // Ensure index is valid before accessing m_tilesets
            if (index >= m_tilesets.size()) continue; 

            //some magic to calculate the tile row & column
            Tileset ts = m_tilesets[index];
            int tilerow = tileID/ts.columns;
            int tilecol = tileID - tilerow * ts.columns - 1;

            //check if this tile is on the last column
            //if we dont do this, the last column in the spritesheet wont get drawn
            if (tileID % ts.columns == 0){
                tilerow -= 1;
                tilecol = ts.columns - 1;
            }

            //Draw each tile to the screen
            TextureManager::GetInstance()->DrawTile(ts.name,ts.tilesize, col*ts.tilesize, row*ts.tilesize, tilerow, tilecol);
        }
    }
}

void TileLayer::Update()
{
}
