#include "main.h"
#include "CPlayer.h"
#pragma once

class CPickup
{
	public:
		CPickup( int lnPickupId, bool lIsOurs = true ) { this->isOurs = lIsOurs; this->nPickupId = lnPickupId; }

	public:
		void SetWorld( int world );
		void SetAlpha( int alpha );
		void SetAuto( bool automatic );
		void SetAutoTimer( int timer );
		void SetPos( Vector pos );

	public:
		int GetWorld();
		int GetAlpha();
		bool GetAuto();
		int GetAutoTimer();
		Vector GetPos();
		int GetModel();
		int GetQuantity();
		int GetID();

	public:
		void Delete();
		bool StreamedToPlayer( CPlayer * player );
			
	public:
		int nPickupId;
		bool isOurs;
};

void RegisterPickup();