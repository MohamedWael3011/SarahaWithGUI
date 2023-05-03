#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
// int main(array<String^>^ args) {
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew SarahaWithGUI::MainForm());
	return 0;
}