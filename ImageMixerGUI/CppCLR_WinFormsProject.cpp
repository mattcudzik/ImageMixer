#include "pch.h"

using namespace System;
#include "MainWIndow.h"
using namespace System::Windows::Forms;

[STAThread]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CppCLRWinFormsProject::MainWindow());
  return 0;
}