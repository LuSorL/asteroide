Source:
	g++ -c Game.cpp -o Game -I include -L lib -l SDL2-2.0.0
	g++ -c Asteroide.cpp -o Asteroide -I include -L lib -l SDL2-2.0.0
	g++ -c vaisseau.cpp -o vaisseau -I include -L lib -l SDL2-2.0.0
	g++ -c Texture.cpp -o Texture -I include -L lib -l SDL2-2.0.0
	g++ -c Bullet.cpp -o Bullet -I include -L lib -l SDL2-2.0.0
	g++  Bullet Texture vaisseau Asteroide Game -c source.cpp -o source -I include -L lib -l SDL2-2.0.0