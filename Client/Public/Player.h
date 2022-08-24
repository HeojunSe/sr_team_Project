#pragma once

#include "Client_Defines.h"
#include "GameObject.h"

BEGIN(Engine)
class CTexture;
class CRenderer;
class CTransform;
//class CVIBuffer_Cube;
class CVIBuffer_Rect;
END

BEGIN(Client)

class CPlayer final : public CGameObject
{
private:
	CPlayer(LPDIRECT3DDEVICE9 pGraphic_Device);
	CPlayer(const CPlayer& rhs);
	virtual ~CPlayer() = default;

public:
	virtual HRESULT Initialize_Prototype() override;
	virtual HRESULT Initialize(void* pArg)override;
	virtual void Tick(_float fTimeDelta)override;
	virtual void Late_Tick(_float fTimeDelta)override;
	virtual HRESULT Render() override;
public:
	CTransform* Get_TransformCom() { return m_pTransformCom; }

private: /* For.Components */
	CTexture*				m_pTextureCom = nullptr;
	CRenderer*				m_pRendererCom = nullptr;
	CTransform*				m_pTransformCom = nullptr;
	//CVIBuffer_Cube*		m_pVIBufferCom = nullptr;
	CVIBuffer_Rect*		m_pVIBufferCom = nullptr;

private:
	HRESULT SetUp_Components();
	HRESULT SetUp_RenderState();
	HRESULT Release_RenderState();

	void Jumping(_float fTimeDelta);

public:
	static CPlayer* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg = nullptr) override;
	virtual void Free() override;

private:

	_uint m_uFrameNum = 0;
	_float m_fFrameTime = 0.f;
	_bool  m_bIdle = true;

};

END