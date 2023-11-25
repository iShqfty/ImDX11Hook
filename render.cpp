#include "render.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_win32.h"

#include "Raw.h"

void SetupImGuiStyle()
{
    // p style from ImThemes
    ImGuiStyle& style = ImGui::GetStyle();

    style.Alpha = 1.0f;
    style.DisabledAlpha = 0.5f;
    style.WindowPadding = ImVec2(5.0f, 5.0f);
    style.WindowRounding = 5.0f;
    style.WindowBorderSize = 0.0f;
    style.WindowMinSize = ImVec2(10.0f, 10.0f);
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    style.WindowMenuButtonPosition = ImGuiDir_None;
    style.ChildRounding = 5.0f;
    style.ChildBorderSize = 1.0f;
    style.PopupRounding = 0.0f;
    style.PopupBorderSize = 0.0f;
    style.FramePadding = ImVec2(5.0f, 3.0f);
    style.FrameRounding = 5.0f;
    style.FrameBorderSize = 1.0f;
    style.ItemSpacing = ImVec2(5.0f, 5.0f);
    style.ItemInnerSpacing = ImVec2(5.0f, 5.0f);
    style.CellPadding = ImVec2(5.0f, 5.0f);
    style.IndentSpacing = 20.0f;
    style.ColumnsMinSpacing = 5.0f;
    style.ScrollbarSize = 12.5f;
    style.ScrollbarRounding = 20.0f;
    style.GrabMinSize = 10.0f;
    style.GrabRounding = 20.0f;
    style.TabRounding = 5.0f;
    style.TabBorderSize = 0.0f;
    style.TabMinWidthForCloseButton = 0.0f;
    style.ColorButtonPosition = ImGuiDir_Right;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.3921568691730499f, 0.3921568691730499f, 0.3921568691730499f, 1.0f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.05882352963089943f, 0.05882352963089943f, 0.05882352963089943f, 1.0f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.05882352963089943f, 0.05882352963089943f, 0.05882352963089943f, 1.0f);
    style.Colors[ImGuiCol_Border] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(9.999999974752427e-07f, 4.248927325534169e-07f, 4.248927325534169e-07f, 0.0f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.09803921729326248f, 0.09803921729326248f, 0.09803921729326248f, 1.0f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.196078434586525f, 0.196078434586525f, 0.196078434586525f, 1.0f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.05882352963089943f, 0.05882352963089943f, 0.05882352963089943f, 1.0f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.05882352963089943f, 0.05882352963089943f, 0.05882352963089943f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.05882352963089943f, 0.05882352963089943f, 0.05882352963089943f, 1.0f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.05882352963089943f, 0.05882352963089943f, 0.05882352963089943f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05882352963089943f, 0.05882352963089943f, 0.05882352963089943f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.196078434586525f, 0.196078434586525f, 0.196078434586525f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.3921568691730499f, 0.3921568691730499f, 0.3921568691730499f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.294117659330368f, 0.294117659330368f, 0.294117659330368f, 1.0f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.3921568691730499f, 0.3921568691730499f, 0.3921568691730499f, 1.0f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.3921568691730499f, 0.3921568691730499f, 0.3921568691730499f, 1.0f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.294117659330368f, 0.294117659330368f, 0.294117659330368f, 1.0f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.09803921729326248f, 0.09803921729326248f, 0.09803921729326248f, 1.0f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.196078434586525f, 0.196078434586525f, 0.196078434586525f, 1.0f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.09803921729326248f, 0.09803921729326248f, 0.09803921729326248f, 1.0f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.196078434586525f, 0.196078434586525f, 0.196078434586525f, 1.0f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
    style.Colors[ImGuiCol_Separator] = ImVec4(0.09803921729326248f, 0.09803921729326248f, 0.09803921729326248f, 1.0f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.196078434586525f, 0.196078434586525f, 0.196078434586525f, 1.0f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.09803921729326248f, 0.09803921729326248f, 0.09803921729326248f, 1.0f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.196078434586525f, 0.196078434586525f, 0.196078434586525f, 1.0f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.09803921729326248f, 0.09803921729326248f, 0.09803921729326248f, 1.0f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.196078434586525f, 0.196078434586525f, 0.196078434586525f, 1.0f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.09803921729326248f, 0.09803921729326248f, 0.09803921729326248f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.3921568691730499f, 0.3921568691730499f, 0.3921568691730499f, 1.0f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.4274509847164154f, 0.3490196168422699f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.8980392217636108f, 0.6980392336845398f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.6000000238418579f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.05882352963089943f, 0.05882352963089943f, 0.05882352963089943f, 1.0f);
    style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.3921568691730499f, 0.3921568691730499f, 0.3921568691730499f, 1.0f);
    style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.3921568691730499f, 0.3921568691730499f, 0.3921568691730499f, 1.0f);
    style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.05999999865889549f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 0.3499999940395355f);
    style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 1.0f, 0.0f, 0.8999999761581421f);
    style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 1.0f);
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.699999988079071f);
    style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.2000000029802322f);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.3499999940395355f);
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;
static uint64_t* g_methodsTable = NULL;

bool rdr::initdx() {
	WNDCLASSEX windowClass;
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = DefWindowProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = GetModuleHandle(NULL);
	windowClass.hIcon = NULL;
	windowClass.hCursor = NULL;
	windowClass.hbrBackground = NULL;
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = "ImDX11";
	windowClass.hIconSm = NULL;

	::RegisterClassEx(&windowClass);

	HWND window = ::CreateWindow(windowClass.lpszClassName, "ImGui DX11 Window", WS_OVERLAPPEDWINDOW, 0, 0, 100, 100, NULL, NULL, windowClass.hInstance, NULL);
	HMODULE libD3D11;
	if ((libD3D11 = ::GetModuleHandle("d3d11.dll")) == NULL)
	{
		::DestroyWindow(window);
		::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
		return 0;
	}

	void* D3D11CreateDeviceAndSwapChain;
	if ((D3D11CreateDeviceAndSwapChain = ::GetProcAddress(libD3D11, "D3D11CreateDeviceAndSwapChain")) == NULL)
	{
		::DestroyWindow(window);
		::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
		return 0;
	}

	D3D_FEATURE_LEVEL featureLevel;
	const D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_11_0 };

	DXGI_RATIONAL refreshRate;
	refreshRate.Numerator = 60;
	refreshRate.Denominator = 1;

	DXGI_MODE_DESC bufferDesc;
	bufferDesc.Width = 100;
	bufferDesc.Height = 100;
	bufferDesc.RefreshRate = refreshRate;
	bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	DXGI_SAMPLE_DESC sampleDesc;
	sampleDesc.Count = 1;
	sampleDesc.Quality = 0;

	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	swapChainDesc.BufferDesc = bufferDesc;
	swapChainDesc.SampleDesc = sampleDesc;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = 1;
	swapChainDesc.OutputWindow = window;
	swapChainDesc.Windowed = 1;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	IDXGISwapChain* swapChain;
	ID3D11Device* device;
	ID3D11DeviceContext* context;

	if (((long(__stdcall*)(
		IDXGIAdapter*,
		D3D_DRIVER_TYPE,
		HMODULE,
		UINT,
		const D3D_FEATURE_LEVEL*,
		UINT,
		UINT,
		const DXGI_SWAP_CHAIN_DESC*,
		IDXGISwapChain**,
		ID3D11Device**,
		D3D_FEATURE_LEVEL*,
		ID3D11DeviceContext**))(D3D11CreateDeviceAndSwapChain))(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, featureLevels, 1, D3D11_SDK_VERSION, &swapChainDesc, &swapChain, &device, &featureLevel, &context) < 0)
	{
		::DestroyWindow(window);
		::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
		return 0;
	}

	g_methodsTable = (uint64_t*)::calloc(205, sizeof(uint64_t));
	::memcpy(g_methodsTable, *(uint64_t**)swapChain, 18 * sizeof(uint64_t));
	::memcpy(g_methodsTable + 18, *(uint64_t**)device, 43 * sizeof(uint64_t));
	::memcpy(g_methodsTable + 18 + 43, *(uint64_t**)context, 144 * sizeof(uint64_t));

	MH_Initialize();

	swapChain->Release();
	swapChain = NULL;

	device->Release();
	device = NULL;

	context->Release();
	context = NULL;

	::DestroyWindow(window);
	::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
	
	return 1;
}

void rdr::init() {
	bool ihook = false;
	do {
		if (rdr::initdx()) {
			ihook = true;
			MH_CreateHook((void*)g_methodsTable[8], hkPresent, (void**)&oPresent);
			MH_EnableHook(MH_ALL_HOOKS);
		}
	} while (!ihook);
}

LRESULT __stdcall rdr::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool hkinit = false;
ImFont* fnt;
HRESULT __stdcall rdr::hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!hkinit)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			ImGui::CreateContext();
			ImGuiIO& io = ImGui::GetIO();
			io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
			ImGui_ImplWin32_Init(window);
			ImGui_ImplDX11_Init(pDevice, pContext);

			// FONTS

			fnt = io.Fonts->AddFontFromMemoryTTF(HelveticaNeueLight, sizeof HelveticaNeueLight, 25.f);
			static const ImWchar icon_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
			ImFontConfig icons_config;
			icons_config.MergeMode = true;
			icons_config.PixelSnapH = true;
			io.Fonts->AddFontFromMemoryTTF(&font_awesome_binary, sizeof font_awesome_binary, 30, &icons_config, icon_ranges);
			hkinit = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImGui::PushFont(fnt);
	SetupImGuiStyle();
	ImGui::ShowDemoWindow();
	ImGui::PopFont();


	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}

void rdr::term() {
	MH_DisableHook(MH_ALL_HOOKS);
	MH_Uninitialize();

	::free(g_methodsTable);
	g_methodsTable = NULL;

	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	SetWindowLongPtr(
		window,
		GWLP_WNDPROC,
		reinterpret_cast<LONG_PTR>(oWndProc)
	);
	if (pDevice) {
		pDevice->Release();
		pDevice = NULL;
	}
	if (pContext) {
		pContext->Release();
		pContext = NULL;
	}
	if (mainRenderTargetView) {
		mainRenderTargetView->Release();
		mainRenderTargetView = NULL;
	}
}