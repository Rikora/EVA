/*
	Utility class to create a render texture (render target)
*/

#pragma once
#include <wrl.h>
#include <d3d11.h>

using namespace Microsoft::WRL;

namespace eva
{
	class RenderTexture
	{
	public:
		RenderTexture() = default;
		RenderTexture(ID3D11Device* device, ID3D11DeviceContext* deviceContext);
		~RenderTexture() = default;
		void CreateRenderTargetAndDepthStencil(UINT width, UINT height, bool multiSampling = false);
		void SetRenderTarget(const FLOAT * color);

	public:
		ID3D11ShaderResourceView* GetShaderResourceView() const;
		UINT GetWidth() const;
		UINT GetHeight() const;
		
	private:
		void CreateRenderTargetView();
		void CreateDepthStencilView();
		void CreateViewport();

	private:
		ComPtr<ID3D11Texture2D> m_renderTargetTexture;
		ComPtr<ID3D11Texture2D> m_depthStencilTexture;
		ComPtr<ID3D11RenderTargetView> m_renderTargetView;
		ComPtr<ID3D11ShaderResourceView> m_shaderResourceView;
		ComPtr<ID3D11DepthStencilView> m_depthStencilView;

	private:
		UINT m_width, m_height;
		D3D11_VIEWPORT m_vp;
		ID3D11Device* m_device;
		ID3D11DeviceContext* m_deviceContext;
		bool m_multiSampling;
	};
}
