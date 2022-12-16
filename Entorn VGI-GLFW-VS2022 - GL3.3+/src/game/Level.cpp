#include "Level.h"
#include "../src/game/graphics/Model.h"
#include "audio/AudioFunctions.h"

Level Level::CURRENT_LEVEL;

void Level::buildFirstLevel(GLuint sh_programID)
{
	Transform tr = Transform();
	tr.position() = vec3(0.0f, 0.0f, Vago::Z_OFFSET); //posicionamos objeto

	Model* model_vago = new Model({ *Mesh::BASIC_CUBE_MESH });

	Vago* vago = new Vago(tr, model_vago, sh_programID);

	Model* model_taula = new Model({ *Mesh::BASIC_CUBE_MESH_BROWN });
	
	float xValorTaula = -110.98f;

	for (int i = 0; i < 1; i++)
	{
		if (i == 2)
		{
			xValorTaula += 4.53f;
			//tercera mesa ha de llegar a 5,69
		}
		else if (i > 0)
		{
			xValorTaula += 2.06f;

		}
		vago->addChild(new Taula(Transform(vec3(xValorTaula, 1.2f, -0.7f), quat(1.0f, 0.0f, 0.0f, 0.0f), vec3(1.0f)), model_taula, sh_programID));
	}

	xValorTaula = -110.98f;

	for (int i = 0; i < 1; i++)
	{
		if (i == 2)
		{
			xValorTaula += 4.53f;
		}
		else if (i > 0)
		{
			xValorTaula += 2.06f;

		}
		vago->addChild(new Taula(Transform(vec3(xValorTaula, -1.2f, -0.7f), quat(1.0f, 0.0f, 0.0f, 0.0f), vec3(1.0f)), model_taula, sh_programID));
	}
	


	Model* model_seient = new Model({ *Mesh::BASIC_CUBE_MESH_SOFT_BROWN });

	quat mirar_endevant = quat(1.0f, 0.0f, 0.0f, 0.0f);
	quat mirar_enrere = quat(glm::cos(glm::pi<float>() / 2), glm::sin(glm::pi<float>() / 2) * 0.0f, glm::sin(glm::pi<float>() / 2) * 0.0f, glm::sin(glm::pi<float>() / 2) * 1.0f);

	float xValorSeientEndavant = -0.31f;

	for (int i = 0; i < 4; i++)
	{
		if (i == 2)
		{
			xValorSeientEndavant += 4.58f;
			//6,34 - i=3
		}
		else if (i > 0)
		{
			xValorSeientEndavant += 2.02f;
			//1,69
		}
		vago->addChild(new Seient(Transform(vec3(xValorSeientEndavant, 1.2f, -1.2f), mirar_endevant, vec3(1.0f)), nullptr, sh_programID));
	}

	xValorSeientEndavant = -0.31f;

	for (int i = 0; i < 4; i++)
	{
		if (i == 2)
		{
			xValorSeientEndavant += 4.58f;
		}
		else if (i > 0)
		{
			xValorSeientEndavant += 2.02f;

		}
		vago->addChild(new Seient(Transform(vec3(xValorSeientEndavant, -1.2f, -1.2f), mirar_endevant, vec3(1.0f)), nullptr, sh_programID));
	}

	float xValorSeientEndarrere = -1.63f;

	
	for (int i = 0; i < 4; i++)
	{
		if (i == 2)
		{
			xValorSeientEndarrere += 4.55f;
			//5,04 - i=3
		}
		else if (i > 0)
		{
			xValorSeientEndarrere += 2.02f;
			//0.39

		}
		vago->addChild(new Seient(Transform(vec3(xValorSeientEndarrere, 1.2f, -1.2f), mirar_enrere, vec3(1.0f)), nullptr, sh_programID));
	}

	xValorSeientEndarrere = -1.63f;

	for (int i = 0; i < 4; i++)
	{
		if (i == 2)
		{
			xValorSeientEndarrere += 4.55f;
		}
		else if (i > 0)
		{
			xValorSeientEndarrere += 2.02f;

		}
		vago->addChild(new Seient(Transform(vec3(xValorSeientEndarrere, -1.2f, -1.2f), mirar_enrere, vec3(1.0f)), nullptr, sh_programID));
	}
	

	Level::CURRENT_LEVEL.my_vago = vago;

	float c = glm::cos(glm::pi<float>() / 4);
	float s = glm::sin(glm::pi<float>() / 4);

	
	Transform trLuisa = Transform();
	trLuisa.position() = vec3(0.1f, 2.2f, 1.0f);
	trLuisa.scale() = vec3(0.04f);
	trLuisa.orientation() = quat(c, s * 1.0f, s * 0.0f, s * 0.0f);
	Cucaracha* luisa = new Cucaracha(trLuisa, new Model("./textures/locker/padlock.obj"), sh_programID);
	Level::CURRENT_LEVEL.cucaracha = luisa;

	//el vagon
	//Transform trRail = Transform();
	//trRail.position() = vec3(0.0f, 0.0f, -2.35f);
	//trRail.scale() = vec3(0.020f);

	//trRail.rotate(glm::pi<float>()/2, vec3(1.0f, 0.0f, 0.0f));
	//Rail* railes = new Rail(trRail, new Model("./textures/vagon/scene.gltf"), sh_programID);

	//tren cartoon
	Transform trRail = Transform();
	trRail.position() = vec3(0.0f, 0.0f, -0.1f);
	trRail.scale() = vec3(1.0f);
	trRail.rotate(glm::pi<float>()/2, vec3(1.0f, 0.0f, 0.0f));
	Rail* railes = new Rail(trRail, new Model("./textures/tren_final/scene.gltf"), sh_programID);
	Level::CURRENT_LEVEL.rail = railes;

	//----------------------------------------------Railes----------------------------------------------
	string llista_rails[] = {"trRail1","trRail2","trRail3","trRail4","trRail5","trRail6","trRail7" ,"trRail8" ,"trRail9" ,"trRail10" ,"trRail11" ,"trRail12" ,"trRail13" ,"trRail14" ,"trRail15" ,"trRail16" ,"trRail17","trRail18"};
	float distance = 6;
	
	Transform trRail1 = Transform();
	trRail1.position() = vec3(6.0f, -1.736f, -1.35f);
	trRail1.scale() = vec3(0.002175f);
	trRail1.rotate(glm::pi<float>() / 2, vec3(1.0f, 0.0f, 0.0f));
	Rail* rail1 = new Rail(trRail1, new Model("./textures/rails/rail1/scene.gltf"), sh_programID);
	Level::CURRENT_LEVEL.rail1 = rail1;
	
	

	Transform trRail2 = Transform();
	trRail2.position() = vec3(14.5f, -1.736f, -1.35f);
	trRail2.scale() = vec3(0.002175f);
	trRail2.rotate(glm::pi<float>() / 2, vec3(1.0f, 0.0f, 0.0f));
	Rail* rail2 = new Rail(trRail2, new Model("./textures/rails/rail2/scene.gltf"), sh_programID);
	Level::CURRENT_LEVEL.rail2 = rail2;


	Transform trRail3 = Transform();
	trRail3.position() = vec3(23.0f, -1.736f, -1.35f);
	trRail3.scale() = vec3(0.002175f);
	trRail3.rotate(glm::pi<float>() / 2, vec3(1.0f, 0.0f, 0.0f));
	Rail* rail3 = new Rail(trRail3, new Model("./textures/rails/rail3/scene.gltf"), sh_programID);
	Level::CURRENT_LEVEL.rail3 = rail3;

	Transform trRail4 = Transform();
	trRail4.position() = vec3(31.5f, -1.736f, -1.35f);
	trRail4.scale() = vec3(0.002175f);
	trRail4.rotate(glm::pi<float>() / 2, vec3(1.0f, 0.0f, 0.0f));
	Rail* rail4 = new Rail(trRail4, new Model("./textures/rails/rail3/scene.gltf"), sh_programID);
	Level::CURRENT_LEVEL.rail4 = rail4;

	Transform trRail5 = Transform();
	trRail5.position() = vec3(40.0f, -1.736f, -1.35f);
	trRail5.scale() = vec3(0.002175f);
	trRail5.rotate(glm::pi<float>() / 2, vec3(1.0f, 0.0f, 0.0f));
	Rail* rail5 = new Rail(trRail5, new Model("./textures/rails/rail3/scene.gltf"), sh_programID);
	Level::CURRENT_LEVEL.rail5 = rail5;

	Transform trRail6 = Transform();
	trRail6.position() = vec3(48.5f, -1.736f, -1.35f);
	trRail6.scale() = vec3(0.002175f);
	trRail6.rotate(glm::pi<float>() / 2, vec3(1.0f, 0.0f, 0.0f));
	Rail* rail6 = new Rail(trRail6, new Model("./textures/rails/rail3/scene.gltf"), sh_programID);
	Level::CURRENT_LEVEL.rail6 = rail6;

	//-------------------------------------------------------------------------------------------------
	Transform trMaletaTapa = Transform();
	trMaletaTapa.position() = vec3(3.5f, 1.0f, 0);
	trMaletaTapa.translate(vec3(0.7f, 0.2f, 0.1f));
	trMaletaTapa.scale(vec3(0.02f));

	GameEntity* maletaTapa = new GameEntity(trMaletaTapa, new Model("./textures/baul_tapa/untitled.obj"), sh_programID);

	Transform trMaleta = Transform();
	trMaleta.position() = vec3(3.5f, 1.0f, 0);
	trMaleta.translate(vec3(0.7f, 0.2f, 0.1f));
	trMaleta.scale(vec3(0.02f));

	Maleta* maleta = new Maleta(trMaleta, new Model("./textures/baul_cuerpo/untitled.obj"), sh_programID, maletaTapa);

	Transform trLibro1 = Transform();
	trLibro1.translate(vec3(0.5, -1.5f, 0.5f));
	trLibro1.scale(vec3(0.2f));
	trLibro1.rotate(PI / -12, vec3(1.0f,0.0f,0.0f));

	Model* llibre_tancat = new Model("./textures/Book/ChurchBookClosedV2/ChurchBookClosedV2-DAE/ChurchBookClosedV2.dae");
	Model* llibre_obert = new Model("./textures/libro1/ChurchBookOpenV2/ChurchBookOpenV2-OBJ/libro_abierto.obj");
	Libro1* libro1 = new Libro1(trLibro1, llibre_tancat, llibre_obert, sh_programID);

	Transform trCrypt = Transform();
	trCrypt.translate(vec3(0.9f, -2.05f, 0.7f));
	trCrypt.scale(vec3(0.2f));
	trCrypt.rotate((PI / -12) * 6, vec3(0.0f, 1.0f, 0.0f));

	Crypt* crypt = new Crypt(trCrypt, new Model("./textures/crypt/crypt.obj"), sh_programID);

	Transform trPanel = Transform();
	trPanel.translate(vec3(0.1f, -2.05f, 1.2f));
	trPanel.scale(vec3(0.02f));

	Panel* panel = new Panel(trPanel, new Model("./textures/panel/calculator.max"), sh_programID);
	
	//-------------------------------------SLENDERMANS----------------------------------------------
	int posicio = 3;
	Transform trPadlock = Transform();
	if (posicio == 1) {
		trPadlock.position() = vec3(7.0f, 0.0f, -0.1f);
		trPadlock.scale() = vec3(0.5f);
		trPadlock.rotate(-(glm::pi<float>() / 2), vec3(1.0f, 0.0f, 0.0f));
	}
	else if (posicio == 2) {
		trPadlock.position() = vec3(-1.0f, 0.0f, -0.1f);
		trPadlock.scale() = vec3(0.5f);
		trPadlock.rotate((glm::pi<float>() / 2), vec3(1.0f, 0.0f, 0.0f));
	}
	else if (posicio == 3) {
		trPadlock.position() = vec3(3.5f, 0.9f, -0.1f);
		trPadlock.scale() = vec3(0.5f);
	}
	else if (posicio == 4) {
		trPadlock.position() = vec3(3.5f, -0.9f, -0.1f);
		trPadlock.scale() = vec3(0.5f);
		trPadlock.rotate((glm::pi<float>()*2), vec3(1.0f, 0.0f, 0.0f));
	}
	Rail* padlock = new Rail(trPadlock, new Model("./textures/slenderman/scene.gltf"), sh_programID);
	padlock->my_enabled = true;

	//pasagero
	/*
	Transform trBilly = Transform();
	trBilly.position() = vec3(8.0f, -1.5f, -0.1f);
	trBilly.scale() = vec3(0.5f);
	trBilly.rotate((glm::pi<float>() / 2), vec3(1.0f, 0.0f, 0.0f));
	Rail* billy = new Rail(trBilly, new Model("./textures/slenderman/scene.gltf"), sh_programID);
	*/




	//exterior tren
	Transform trExterior = Transform();
	trExterior.position() = vec3(0.0f, 0.0f, 50.0f);
	trExterior.scale() = vec3(0.2f);

	trExterior.rotate(glm::pi<float>()/2, vec3(0.0f, 0.0f, 1.0f));
	trExterior.rotate(glm::pi<float>() /2, vec3(1.0f, 0.0f, 0.0f));

	Rail* exterior = new Rail(trExterior, new Model("./textures/tren_exterior/scene.gltf"), sh_programID);

	//megafono
	Transform trMegafono = Transform();
	trMegafono.position() = vec3(9.08f, 0.0f, 2.5f);
	trMegafono.scale() = vec3(1.6f);

	trMegafono.rotate(glm::pi<float>() / 2, vec3(0.0f, 0.0f, 1.0f));
	//trMegafono.rotate((3*glm::pi<float>() / 4), vec3(1.0f, 0.0f, 0.0f));
	trMegafono.rotate((glm::pi<float>() / 5), vec3(0.0f, -1.0f, 0.0f));
	//trMegafono.rotate(-(3*glm::pi<float>() / 4), vec3(1.0f, 0.0f, 0.0f));
	//trMegafono.rotate(-(3 * glm::pi<float>() / 4), vec3(0.0f, 0.0f, 1.0f));
	Rail* megafono = new Rail(trMegafono, new Model("./textures/megafono/scene.gltf"), sh_programID);





	Level::CURRENT_LEVEL.padlock = padlock;

	Level::CURRENT_LEVEL.my_vago = vago;
	Level::CURRENT_LEVEL.maleta = maleta;
	Level::CURRENT_LEVEL.maletaTapa = maletaTapa;
	Level::CURRENT_LEVEL.libro1 = libro1;
	Level::CURRENT_LEVEL.crypt = crypt;
	Level::CURRENT_LEVEL.panel = panel;
	Level::CURRENT_LEVEL.my_entity_under_cursor = nullptr;
	Level::CURRENT_LEVEL.megaphone = megafono;
	Level::CURRENT_LEVEL.exterior_tren = exterior;
}

void Level::MaybeSpawnSlender()
{
	/* initialize random seed: */
	srand(time(NULL));

	/* generate random number between 1 and 10: */
	int iSecret = rand() % 10 + 1;

	std::cout << "isecret = " << iSecret << std::endl;
	iSecret = 5;
	if (iSecret == 5)
	{
		// Activar spooky lighting
		*llumAmbient = false;
		*iFixe = true;

		// Reproduir audio
		//audio2.play2D("./media/light_flickering.wav", false, false);
		Audio::AUDIO_FUNCTIONS.play2D("./media/spooky_sound.wav", false, false);

		// Mostrar slenderman
		padlock->my_enabled = true;
	}
}

void Level::despawnSlender()
{
	// return to normal lighting
	*llumAmbient = true;
	*iFixe = false;

	padlock->my_enabled = false;
}



