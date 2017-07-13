#include "Model.h"

std::vector<Vec3>* Model::getVerts()
{
	return m_vertices;
}

std::vector<unsigned int>* Model::getIndexBuffer()
{
	return m_indexBuffer;
}