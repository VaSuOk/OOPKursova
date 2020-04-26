#include "TileLayer.h"


TileLayer::TileLayer(int tilesize, int rowcount, int colcount, TileMap tileMap, TilesetList tilesets): m_Tilesets (tilesize)
{

    m_RowCount = rowcount;
    m_ColCount = colcount;
    m_Tilemap = tileMap;
    m_Tilesets = tilesets;
}

void TileLayer::Render()
{

}

void TileLayer::Update()
{

}
