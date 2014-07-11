#include "CCore.h"
#include "CPickup.h"
#include "main.h"

// Core instance
extern CCore * pCore;

void CPickup::SetWorld( int world ) { functions->SetPickupWorld( this->nPickupId, world ); }
void CPickup::SetAlpha( int alpha ) { functions->PickupSetAlpha( this->nPickupId, alpha ); }
void CPickup::SetAuto( bool automatic ) { functions->PickupSetAutomatic( this->nPickupId, automatic ); }
void CPickup::SetAutoTimer( int timer ) { functions->SetPickupAutoTimer( this->nPickupId, timer ); }
void CPickup::SetPos( Vector pos ) { functions->PickupSetPos( this->nPickupId, pos.x, pos.y, pos.z ); }

int CPickup::GetWorld() { return functions->GetPickupWorld( this->nPickupId ); }
int CPickup::GetAlpha() { return functions->PickupGetAlpha(this->nPickupId); }
bool CPickup::GetAuto() { return (functions->PickupIsAutomatic(this->nPickupId) == 1 ? true : false); }
int CPickup::GetAutoTimer() { return functions->GetPickupAutoTimer(this->nPickupId); }

EntityVector CPickup::GetPos()
{
	float x, y, z;
	functions->PickupGetPos( this->nPickupId, &x, &y, &z );

	return EntityVector( this->nPickupId, ENTITY_PICKUP, -1, x, y, z );
}

int CPickup::GetModel() { return functions->PickupGetModel(this->nPickupId); }
int CPickup::GetQuantity() { return functions->PickupGetQuantity(this->nPickupId); }
void CPickup::Delete()
{
	//PS! this instance will be deleted due to a callback!!!
	functions->DeletePickup( this->nPickupId );
}

int CPickup::GetID() { return this->nPickupId; }
bool CPickup::StreamedToPlayer(CPlayer * player) { return (functions->IsPickupStreamedForPlayer(this->nPickupId, player->nPlayerId) == 1 ? true : false); }

void RegisterPickup()
{
	Class<CPickup> c(v, "CPickup_INTERNAL");

	// Read-write properties
	c
		.Prop( _SC("World"), &CPickup::GetWorld, &CPickup::SetWorld )
		.Prop( _SC("Alpha"), &CPickup::GetAlpha, &CPickup::SetAlpha )
		.Prop( _SC("Automatic"), &CPickup::GetAuto, &CPickup::SetAuto )
		.Prop( _SC("Timer"), &CPickup::GetAutoTimer, &CPickup::SetAutoTimer )
		.Prop( _SC("Pos"), &CPickup::GetPos, &CPickup::SetPos );

	// Read-only properties
	c
		.Prop( _SC("Model"), &CPickup::GetModel )
		.Prop( _SC("Quantity"), &CPickup::GetQuantity )
		.Prop( _SC("ID"), &CPickup::GetID );

	// Functions
	c
		.Func( _SC("Remove"), &CPickup::Delete )
		.Func( _SC("StreamedToPlayer"), &CPickup::StreamedToPlayer );

	RootTable(v).Bind( _SC("CPickup"), c );
}