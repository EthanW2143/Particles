#include "Engine.h"

using namespace sf;
using namespace std;

void Engine::Engine()
{
  VideoMode vm(1920, 1080);
  m_Window.create(vm, "Particles", Style::Default);
}

void Engine::run()
{
  Clock tpf;
  Particle p;
  
  cout << "Starting Particle unit tests..." << endl;
  Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
  p.unitTests();
  cout << "Unit tests complete.  Starting engine..." << endl;

  while (m_Window.isOpen())
    {
      tpf.restart();
      Time elapsedTime = tpf.getElapsedTime();
      float dtAsSeconds = elapsedTime.asSeconds();
      input();
      update(dtAsSeconds);
      draw();
    }
}

void Engine::input()
{
  Event event;
  //Event handling
  while (m_Window.pollEvent(event))
    {
      if (event.type == Event::Closed)
        {
			  // Quit the game when the window is closed
			  m_Window.close(); 
        }
      
      if (Keyboard::isKeyPressed(Keyboard::Escape))
     			 {
        			m_Window.close();
     			 }

      if (event.type == sf::Event::MouseButtonPressed)
        {
          // Left Mouse Click event 
          // will zoomIn and call setCenter
          // on the ComplexPlane object with the (x,y) pixel location of the mouse click
              
          if (event.mouseButton.button == sf::Mouse::Left)
            {
              for (int i = 0; i < 4; i++)
                {
                  //numPoints is a number between 25 and 50
                  int numPoints = rand() % 26 + 25
                  Particle p(m_Window&, numPoints,Vector2i(event.mouseButton.x, event.mouseButton.y));
                }

            }
        }            
    }


}

void Engine::update(float dtAsSeconds)
{
     for (auto it = m_particles.begin(); it != m_particles.end();)
	{
	     if (it->getTTL() > 0.0)
		{
		     it->update(dtAsSeconds);
		     it++;
		}

	     else
		{
		     it = m_particles.erase(it);
		}
	}
}

void Engine::draw()
{
    RenderStates states = RenderStates::Default;
    m_Window.clear();
    for (int i = 0; i < m_particles.size(); i++)
    {
        m_particles.at(i).draw(m_Window, states);
    }
    m_Window.display();
}
