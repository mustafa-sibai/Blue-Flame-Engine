#include "AWindow.h"
#include "BF/System/Log.h"

namespace BF
{
	namespace Platform
	{
		namespace Android
		{
			AWindow::AWindow() :
				window(nullptr)
			{
				BF_LOG_INFO("~AWindow");
			}

			AWindow::~AWindow()
			{
				BF_LOG_INFO("~AWindow");
			}

			void AWindow::Initialize()
			{
				BF_LOG_INFO("AWindow Initialize");
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