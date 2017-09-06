#include "bulletEngine.h"
#include "cw/things.h"
#include <glm/exponential.hpp>
#include "mainGameScreen.h"


void bulletEngine::doStuff() {
	//remove bullets that have less than 0 life left
	//auto it = std::partition(m_bullets.begin(), m_bullets.end(), [](const auto& a) {return a.life > 0; });
	m_parent.bullets.erase(std::partition(m_parent.bullets.begin(), m_parent.bullets.end(), [](bullet& a) {a.pos += a.speed*a.angle; return a.life-- > 0; }), m_parent.bullets.end());
	if(++m_ticks%2)
		bulletCollision();
}

void bulletEngine::bulletCollision(){
	for (int i = m_parent.bullets.size()-1; i >=0 ; --i) {
		for (int j = m_parent.enemies.size()-1; j >=0 ; --j) {
			if (circleInCircle(
					m_parent.enemies[j]->getPos(), enemy::radius,
					m_parent.bullets[i].pos, bullet::radius)) {
				if (m_parent.enemies[j]->loseHP(m_parent.bullets[i].dmg) == dead) {
					std::swap(m_parent.enemies[j], m_parent.enemies.back());
					m_parent.enemies.pop_back();
				}std::swap(m_parent.bullets[i], m_parent.bullets.back());
				m_parent.bullets.pop_back();
				break;
			}
		}if (circleInCircle(
				m_parent.getPlayer().getPos(), player::radius,
				m_parent.bullets[i].pos, bullet::radius)) {
			m_parent.getPlayer().loseHP(m_parent.bullets[i].dmg);
			std::swap(m_parent.bullets[i], m_parent.bullets.back());
			m_parent.bullets.pop_back();
		}
	}
}
