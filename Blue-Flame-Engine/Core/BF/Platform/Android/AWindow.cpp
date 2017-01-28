#include "AWindow.h"
#include "BF/System/Log.h"

namespace BF
{
	namespace Platform
	{
		namespace Android
		{
			ANativeWindow* AWindow::window = nullptr;

			AWindow::AWindow()
			{
				BF_LOG_INFO("~AWindow");
			}

			AWindow::~AWindow()
			{
				BF_LOG_INFO("~AWindow");
			}

			void AWindow::Update()
			{
			}

			bool AWindow::IsOpen()
			{
				return true;
			}
		}
	}
}