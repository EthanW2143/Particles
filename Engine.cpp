#include "Engine.h"

using namespace sf;
using namespace std;

void Engine::Engine()
{
  VideoMode vm(1920, 1080);
  m_Window(vm, "Mandelbrot", Style::Default);
}

void Engine::run()
{
  Clock tpf;
  Particle p;
  
  cout << "Starting Particle unit tests..." << endl;
  Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
  p.unitTests();
  cout << "Unit tests complete.  Starting engine..." << endl;
  

}

void Engine::input()
{

}

void Engine::update(float dtAsSeconds)
{

}

void Engine::draw()
{

}
