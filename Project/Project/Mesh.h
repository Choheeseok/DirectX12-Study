#pragma once

// 정점을 표현하기 위한클래스를 선언한다.
class Vertex
{
protected:
	// 정점의 위치 벡터이다(모든 정점은 최소한 위치 벡터를 가져야 한다).
	XMFLOAT3 m_xmf3Position;

public:
	Vertex() { m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f); }
	Vertex(XMFLOAT3 xmf3Position) { m_xmf3Position = xmf3Position; }
	~Vertex() {}
};

class DiffusedVertex : public Vertex
{
protected:
	// 정점의 색상이다.
	XMFLOAT4 m_xmf4Diffuse;

public:
	DiffusedVertex() {}
	DiffusedVertex(float x, float y, float z, XMFLOAT4 xmf4Diffuse) {
		m_xmf3Position = XMFLOAT3(x, y, z);
		m_xmf4Diffuse = xmf4Diffuse;
	}
	DiffusedVertex(XMFLOAT3 xmf3Position, XMFLOAT4 xmf4Diffuse) {
		m_xmf3Position = xmf3Position;
		m_xmf4Diffuse = xmf4Diffuse;
	}
	~DiffusedVertex() { }
};

class Mesh
{
public:
	Mesh(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual ~Mesh();

private:
	int m_nReferences = 0;

public:
	void AddRef() { m_nReferences++; }
	void Release() { if (--m_nReferences <= 0) delete this; }

	void ReleaseUploadBuffers();

protected:
	ID3D12Resource* m_pd3dVertexBuffer = NULL;
	ID3D12Resource* m_pd3dVertexUploadBuffer = NULL;

	D3D12_VERTEX_BUFFER_VIEW m_d3dVertexBufferView;

	D3D12_PRIMITIVE_TOPOLOGY m_d3dPrimitiveTopology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	UINT m_nSlot = 0;
	UINT m_nVertices = 0;
	UINT m_nStride = 0;
	UINT m_nOffset = 0;

public:
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList);
};

class TriangleMesh : public Mesh
{
public:
	TriangleMesh(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual ~TriangleMesh() {}
};