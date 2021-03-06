//Standard libs
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <iostream>

//Dear ImGui
#include "imgui.h"
#include "imgui-SFML.h"

//SFML
#include "SFML/Graphics.hpp"


#define TARGET_WINDOW_NAME "sandbox-sfml-imgui"
#define TARGET_WINDOW_LENGTH 1920
#define TARGET_WINDOW_HEIGHT 1080
#define TARGET_FRAMERATE 60

INT32 APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ INT32 nCmdShow)
{
	OutputDebugString("Start application\n");

	sf::RenderWindow window(sf::VideoMode(TARGET_WINDOW_LENGTH, TARGET_WINDOW_HEIGHT), TARGET_WINDOW_NAME, sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(TARGET_FRAMERATE);

	ImGui::SFML::Init(window);

	sf::Clock deltaClock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		
		//Draw ImGui
		ImGui::SFML::Update(window, deltaClock.restart());
		
		//Clear old frame
		window.clear();

		//Render ImGui and draw the frame
		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();

	return EXIT_SUCCESS;
}