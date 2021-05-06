#pragma once
#include "Timer.h"

class Scene
{
public:
	Scene();
	~Scene();

	bool OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	bool OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);

	void BuildObjects(ID3D12Device* pd3dDevice);
	void ReleaseObjects();

	bool ProcessInput();
	void AnimateObjects(float fTimeElapsed);
	void Render(ID3D12GraphicsCommandList* pd3dCommandList);

	ID3D12RootSignature* m_pd3dGraphicsRootSignature;
	// ��Ʈ �ñ׳�ó�� ��Ÿ���� �������̽� �������̴�.
	ID3D12PipelineState* m_pd3dPipelineState;
	// ���������� ���¸� ��Ÿ���� �������̽� �������̴�.
};