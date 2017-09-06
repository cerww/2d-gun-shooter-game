#include "enemy.h"

enemy::enemy(glm::vec4 t_pos,texture t_text,gun t_gun):
	m_gun(t_gun),
	entity(t_pos,t_text){

}
