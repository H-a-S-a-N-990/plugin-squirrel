#include "CObject.h"
#include "CPlayer.h"
#include "CVehicle.h"
#include "CCore.h"
#include "main.h"

inline bool Boolify( unsigned int n ) { return ( n ? true : false ); }

// The core
extern CCore * pCore;

void CPlayer::SetPosition( Vector pos ) { functions->SetPlayerPos( this->nPlayerId, pos.x, pos.y, pos.z ); }
void CPlayer::SetHealth( float health ) { functions->SetPlayerHealth( this->nPlayerId, health ); }
void CPlayer::SetArmour( float armour ) { functions->SetPlayerArmour( this->nPlayerId, armour ); }

bool CPlayer::StreamedToPlayer( CPlayer * player )
{
	if( player != nullptr )
		return Boolify( functions->IsPlayerStreamedForPlayer( player->nPlayerId, this->nPlayerId ) );

	return false;
}

void CPlayer::SetAdmin( bool toSetAdmin ) { functions->SetPlayerAdmin( this->nPlayerId, toSetAdmin ); }
void CPlayer::SetWorld( int world ) { functions->SetPlayerWorld( this->nPlayerId, world ); }
void CPlayer::SetSecWorld( int world ) { functions->SetPlayerSecWorld( this->nPlayerId, world ); }
void CPlayer::SetTeam( int team ) { functions->SetPlayerTeam( this->nPlayerId, team ); }
void CPlayer::SetSkin( int skin ) { functions->SetPlayerSkin( this->nPlayerId, skin ); }
void CPlayer::SetColour( cRGB colour ) { functions->SetPlayerColour( this->nPlayerId, colour.toUInt() ); }

void CPlayer::SetMoney( int money )
{
	int oldCash = functions->GetPlayerMoney( this->nPlayerId );

	Function callback = RootTable().GetFunction( _SC("onPlayerCashChange") );
	if( !callback.IsNull() )
		callback( pCore->RetrievePlayer(this->nPlayerId), oldCash, money );

	functions->SetPlayerMoney( this->nPlayerId, money );
}

void CPlayer::SetScore( int score )
{
	int oldScore = functions->GetPlayerScore( this->nPlayerId );

	Function callback = RootTable().GetFunction( _SC("onPlayerScoreChange") );
	if( !callback.IsNull() )
		callback( pCore->RetrievePlayer(this->nPlayerId), oldScore, score );

	functions->SetPlayerScore( this->nPlayerId, score );
}

void CPlayer::SetImmunity( unsigned int immunity ) { functions->SetPlayerImmunityFlags( this->nPlayerId, immunity ); }
void CPlayer::SetHeading( float heading ) { functions->SetPlayerHeading( this->nPlayerId, heading ); }
void CPlayer::SetAlpha( int alpha, int fadeTime ) { functions->SetPlayerAlpha( this->nPlayerId, alpha, fadeTime ); }
void CPlayer::SetVehicle( CVehicle * vehiclePointer )
{
	// <TODO>
	// Need to get this and other classes to derive from a base class so I can
	// check the entity type properly.
	if( vehiclePointer != nullptr )
	{
		Function callback = RootTable().GetFunction( _SC("onPlayerEnterVehicle") );
		if( !callback.IsNull() )
			callback( pCore->RetrievePlayer(this->nPlayerId), vehiclePointer );

		functions->PutPlayerInVehicle( this->nPlayerId, vehiclePointer->nVehicleId, 0, 1, 1 );
	}
}

void CPlayer::SetFrozen( bool toFreeze ) { functions->TogglePlayerControllable( this->nPlayerId, !toFreeze ); }
void CPlayer::SetDrivebyEnabled( bool canDb ) { functions->TogglePlayerDriveby( this->nPlayerId, canDb ); }
void CPlayer::SetWhiteScanlines( bool hasWhiteScan ) { functions->TogglePlayerWhiteScanlines( this->nPlayerId, hasWhiteScan ); }
void CPlayer::SetGreenScanlines( bool hasGreenScan ) { functions->TogglePlayerGreenScanlines( this->nPlayerId, hasGreenScan ); }
void CPlayer::SetWidescreen( bool hasWidescreen ) { functions->TogglePlayerWidescreen( this->nPlayerId, hasWidescreen ); }
void CPlayer::SetOnRadar( bool showOnRadar ) { functions->TogglePlayerHasMarker( this->nPlayerId, showOnRadar ); }
void CPlayer::SetCanAttack( bool canAttack ) { functions->TogglePlayerAttackPriv( this->nPlayerId, canAttack ); }
void CPlayer::SetWeaponSlot( int slot ) { functions->SetPlayerWeaponSlot( this->nPlayerId, slot ); }

EntityVector CPlayer::GetPosition()
{
	float x, y, z;
	functions->GetPlayerPos(this->nPlayerId, &x, &y, &z);

	return EntityVector(this->nPlayerId, ENTITY_PLAYER, -1, x, y, z);
}

int CPlayer::GetClass() { return functions->GetPlayerClass(this->nPlayerId); }
bool CPlayer::GetAdmin() { return Boolify(functions->IsPlayerAdmin(this->nPlayerId) == 1); }
bool CPlayer::Typing() { return Boolify(functions->IsPlayerTyping(this->nPlayerId)); }

SQChar * CPlayer::GetIP()
{
	functions->GetPlayerIP( this->nPlayerId, this->ip, 17 );
	return this->ip;
}

bool CPlayer::GetSpawned() { return Boolify(functions->IsPlayerSpawned(this->nPlayerId) == 1); }
int CPlayer::GetWorld() { return functions->GetPlayerWorld(this->nPlayerId); }
int CPlayer::GetSecWorld() { return functions->GetPlayerSecWorld(this->nPlayerId); }
int CPlayer::GetUniqueWorld() { return functions->GetPlayerUniqueWorld(this->nPlayerId); }
int CPlayer::GetState() { return functions->GetPlayerState(this->nPlayerId); }

Sqrat::string CPlayer::GetName()
{
	memset(this->name, '\0', sizeof(this->name));
	functions->GetPlayerName(this->nPlayerId, this->name, sizeof(this->name));

	return this->name;
}

int CPlayer::GetTeam() { return functions->GetPlayerTeam(this->nPlayerId); }
int CPlayer::GetSkin() { return functions->GetPlayerSkin(this->nPlayerId); }

EntityRGB CPlayer::GetColour()
{
	unsigned int colour = functions->GetPlayerColour( this->nPlayerId );
	unsigned char r     = (colour >> 16) & 0xff;
	unsigned char g     = (colour >> 8) & 0xff;
	unsigned char b     = colour & 0xff;

	EntityRGB rgb(this->nPlayerId, ENTITY_PLAYER, 0, r, g, b);
	return rgb;
}

int CPlayer::GetMoney() { return functions->GetPlayerMoney(this->nPlayerId); }
int CPlayer::GetScore() { return functions->GetPlayerScore(this->nPlayerId); }
int CPlayer::GetPing() { return functions->GetPlayerPing(this->nPlayerId); }
float CPlayer::GetHealth() { return functions->GetPlayerHealth(this->nPlayerId); }
float CPlayer::GetArmour() { return functions->GetPlayerArmour(this->nPlayerId); }
unsigned int CPlayer::GetImmunity() { return functions->GetPlayerImmunityFlags(this->nPlayerId); }
float CPlayer::GetHeading() { return functions->GetPlayerHeading(this->nPlayerId); }
int CPlayer::GetAlpha() { return functions->GetPlayerAlpha(this->nPlayerId); }

CVehicle * CPlayer::GetVehicle()
{
	int vehicleId = functions->GetPlayerVehicleID( this->nPlayerId );
	return pCore->RetrieveVehicle(vehicleId);
}

bool CPlayer::GetFrozen() { return !functions->EnabledPlayerControllable(this->nPlayerId); }
bool CPlayer::GetDrivebyEnabled() { return Boolify(functions->EnabledPlayerDriveby(this->nPlayerId)); }
bool CPlayer::GetWhiteScanlines() { return Boolify(functions->EnabledPlayerWhiteScanlines(this->nPlayerId)); }
bool CPlayer::GetGreenScanlines() { return Boolify(functions->EnabledPlayerGreenScanlines(this->nPlayerId)); }
bool CPlayer::GetWidescreen() { return Boolify(functions->EnabledPlayerWidescreen(this->nPlayerId)); }
bool CPlayer::GetOnRadar() { return Boolify(functions->EnabledPlayerHasMarker(this->nPlayerId)); }
bool CPlayer::GetCanAttack() { return Boolify(functions->EnabledPlayerAttackPriv(this->nPlayerId)); }
int CPlayer::GetWeaponSlot() { return functions->GetPlayerWeaponSlot(this->nPlayerId); }
int CPlayer::GetWeapon() { return functions->GetPlayerWeapon(this->nPlayerId); }
int CPlayer::GetWeaponAmmo() { return functions->GetPlayerWeaponAmmo(this->nPlayerId); }

void CPlayer::Kick() { functions->KickPlayer( this->nPlayerId ); }
void CPlayer::Ban() { functions->BanPlayer( this->nPlayerId ); }
void CPlayer::Spawn() { functions->ForcePlayerSpawn(this->nPlayerId); }
void CPlayer::GiveMoney( int money ) { functions->GivePlayerMoney( this->nPlayerId, money ); }

void CPlayer::ShowMarkers( bool setMarkers ) { functions->TogglePlayerShowMarkers( this->nPlayerId, setMarkers ); }
bool CPlayer::ShowingMarkers() { return Boolify(functions->EnabledPlayerShowMarkers(this->nPlayerId)); }

void CPlayer::SetSpectateTarget(CPlayer * pTarget)
{
	if (pTarget == nullptr)
		functions->SetPlayerSpectateTarget(this->nPlayerId, -1);
	else
		functions->SetPlayerSpectateTarget(this->nPlayerId, pTarget->nPlayerId);
}

CPlayer * CPlayer::GetSpectateTarget()
{
	int target = functions->GetPlayerSpectateTarget(this->nPlayerId);
	return pCore->RetrievePlayer(target);
}

void CPlayer::AddSpeed( Vector speed )
{
	float x = speed.x;
	float y = speed.y;
	float z = speed.z;

	functions->AddPlayerSpeed( this->nPlayerId, x, y, z );
}

void CPlayer::SetInterior( int interior ) { OutputWarning( "Player.SetInterior is deprecated. Teleport them to the interior loc instead." ); }
void CPlayer::Eject() { functions->RemovePlayerFromVehicle(this->nPlayerId); }
void CPlayer::SetWantedLevel( int wantedLevel ) { functions->SetPlayerWantedLevel( this->nPlayerId, wantedLevel ); }

void CPlayer::SetCameraPos( Vector pos, Vector look )
{
	float cX = pos.x;
	float cY = pos.y;
	float cZ = pos.z;

	float lX = look.x;
	float lY = look.y;
	float lZ = look.z;

	functions->SetCameraPosition( this->nPlayerId, cX, cY, cZ, lX, lY, lZ );
}

void CPlayer::Disarm() { functions->RemoveAllWeapons(this->nPlayerId); }
void CPlayer::CompatAnimation( int anim ) { functions->SetPlayerAnimation( this->nPlayerId, 0, anim ); }
void CPlayer::Animation( int group, int anim ) { functions->SetPlayerAnimation( this->nPlayerId, group, anim ); }

CVehicle * CPlayer::StandingOnVehicle()
{
	int veh = functions->GetPlayerStandingOnVehicle( this->nPlayerId );
	return pCore->RetrieveVehicle(veh);
}

CObject * CPlayer::StandingOnObject()
{
	int obj = functions->GetPlayerStandingOnObject( this->nPlayerId );
	if( obj < 1 )
		return nullptr;
	else
	{
		this->standingOn.nObjectId = obj;
		return &this->standingOn;
	}
}

void CPlayer::GiveWeapon( int weapon, int ammo ) { functions->GivePlayerWeapon( this->nPlayerId, weapon, ammo ); }
void CPlayer::SetWeapon( int weapon, int ammo ) { functions->SetPlayerWeapon( this->nPlayerId, weapon, ammo ); }
void CPlayer::RemoveWeapon( int weapon ) { functions->RemovePlayerWeapon( this->nPlayerId, weapon ); }
int CPlayer::GetWeaponAtSlot( int slot ) { return functions->GetPlayerWeaponAtSlot( this->nPlayerId, slot ); }
int CPlayer::GetAmmoAtSlot( int slot ) { return functions->GetPlayerAmmoAtSlot( this->nPlayerId, slot ); }
int CPlayer::GetID() { return this->nPlayerId; }
void CPlayer::Select() { functions->ForcePlayerSelect(this->nPlayerId); }
bool CPlayer::GetCameraLocked() { return Boolify(functions->IsCameraLocked(this->nPlayerId)); }
void CPlayer::RestoreCamera() { functions->RestoreCamera(this->nPlayerId); }
int CPlayer::GetKey() { return functions->GetPlayerKey(this->nPlayerId); }
double CPlayer::GetFPS() { return functions->GetPlayerFPS(this->nPlayerId); }

void CPlayer::SetMarker(int nDummy) { functions->TogglePlayerHasMarker(this->nPlayerId, 1); }
void CPlayer::RemoveMarker() { functions->TogglePlayerHasMarker(this->nPlayerId, 0); }
bool CPlayer::GetMarkerVisible() { return functions->EnabledPlayerHasMarker(this->nPlayerId) == 1; }
void CPlayer::SetMarkerVisible(bool isVisible) { functions->TogglePlayerHasMarker(this->nPlayerId, isVisible); }

bool CPlayer::GetAwayStatus() { return functions->IsPlayerAway(this->nPlayerId) == 1; }
bool CPlayer::GetCanUseColors() { return functions->EnabledPlayerChatTags(this->nPlayerId) == 1; }
void CPlayer::SetCanUseColors(bool canUse) { functions->TogglePlayerChatTagsEnabled(this->nPlayerId, canUse); }

bool CPlayer::GetDrunkStatus() { return functions->EnabledPlayerDrunkEffects(this->nPlayerId) == 1; }
void CPlayer::SetDrunkStatus(bool isDrunk) { functions->TogglePlayerDrunkEffects(this->nPlayerId, isDrunk); }
void CPlayer::SetDrunkLevel(int visuals, int handling)
{
	if (visuals <= 0 && handling <= 0)
		functions->TogglePlayerDrunkEffects(this->nPlayerId, 0);
	else
		functions->TogglePlayerDrunkEffects(this->nPlayerId, 1);
}

SQChar * CPlayer::GetUniqueID()
{
	functions->GetPlayerUID(this->nPlayerId, this->uid, 40);
	return uid;
}

Sqrat::string PlayerToString(CPlayer * p)
{
	return p->GetName();;
}

void RegisterPlayer()
{
	Class<CPlayer> c(v, "CPlayer_INTERNAL");

	// Read-write properties
	c
		.Prop(_SC("Admin"), &CPlayer::GetAdmin, &CPlayer::SetAdmin)
		.Prop(_SC("Angle"), &CPlayer::GetHeading, &CPlayer::SetHeading)
		.Prop(_SC("Armor"), &CPlayer::GetArmour, &CPlayer::SetArmour)
		.Prop(_SC("Armour"), &CPlayer::GetArmour, &CPlayer::SetArmour)
		.Prop(_SC("CanAttack"), &CPlayer::GetCanAttack, &CPlayer::SetCanAttack)
		.Prop(_SC("CanDriveby"), &CPlayer::GetDrivebyEnabled, &CPlayer::SetDrivebyEnabled)
		.Prop(_SC("Cash"), &CPlayer::GetMoney, &CPlayer::SetMoney)
		.Prop(_SC("Color"), &CPlayer::GetColour, &CPlayer::SetColour)
		.Prop(_SC("Colour"), &CPlayer::GetColour, &CPlayer::SetColour)
		.Prop(_SC("DrivebyAbility"), &CPlayer::GetDrivebyEnabled, &CPlayer::SetDrivebyEnabled)
		.Prop(_SC("Frozen"), &CPlayer::GetFrozen, &CPlayer::SetFrozen)
		.Prop(_SC("GreenScanlines"), &CPlayer::GetGreenScanlines, &CPlayer::SetGreenScanlines)
		.Prop(_SC("HasChatTags"), &CPlayer::GetCanUseColors, &CPlayer::SetCanUseColors)
		.Prop(_SC("HasMarker"), &CPlayer::GetMarkerVisible, &CPlayer::SetMarkerVisible)
		.Prop(_SC("Heading"), &CPlayer::GetHeading, &CPlayer::SetHeading)
		.Prop(_SC("Health"), &CPlayer::GetHealth, &CPlayer::SetHealth)
		.Prop(_SC("Immunity"), &CPlayer::GetImmunity, &CPlayer::SetImmunity)
		.Prop(_SC("IsAdmin"), &CPlayer::GetAdmin, &CPlayer::SetAdmin)
		.Prop(_SC("IsDrunk"), &CPlayer::GetDrunkStatus, &CPlayer::SetDrunkStatus)
		.Prop(_SC("IsFrozen"), &CPlayer::GetFrozen, &CPlayer::SetFrozen)
		.Prop(_SC("IsOnRadar"), &CPlayer::GetOnRadar, &CPlayer::SetOnRadar)
		.Prop(_SC("IsWeaponSyncBlocked"), &CPlayer::GetCanAttack, &CPlayer::SetCanAttack)
		.Prop(_SC("Money"), &CPlayer::GetMoney, &CPlayer::SetMoney)
		.Prop(_SC("Pos"), &CPlayer::GetPosition, &CPlayer::SetPosition)
		.Prop(_SC("Score"), &CPlayer::GetScore, &CPlayer::SetScore)
		.Prop(_SC("SecWorld"), &CPlayer::GetSecWorld, &CPlayer::SetSecWorld)
		.Prop(_SC("ShowMarkers"), &CPlayer::ShowingMarkers, &CPlayer::ShowMarkers)
		.Prop(_SC("Slot"), &CPlayer::GetWeaponSlot, &CPlayer::SetWeaponSlot)
		.Prop(_SC("Skin"), &CPlayer::GetSkin, &CPlayer::SetSkin)
		.Prop(_SC("SpectateTarget"), &CPlayer::GetSpectateTarget, &CPlayer::SetSpectateTarget)
		.Prop(_SC("Team"), &CPlayer::GetTeam, &CPlayer::SetTeam)
		.Prop(_SC("Vehicle"), &CPlayer::GetVehicle, &CPlayer::SetVehicle)
		.Prop(_SC("WhiteScanlines"), &CPlayer::GetWhiteScanlines, &CPlayer::SetWhiteScanlines)
		.Prop(_SC("Widescreen"), &CPlayer::GetWidescreen, &CPlayer::SetWidescreen)
		.Prop(_SC("World"), &CPlayer::GetWorld, &CPlayer::SetWorld);

	// Read-only properties
	c
		.Prop(_SC("Alpha"), &CPlayer::GetAlpha)
		.Prop(_SC("Ammo"), &CPlayer::GetWeaponAmmo)
		.Prop(_SC("Away"), &CPlayer::GetAwayStatus)
		.Prop(_SC("CameraLocked"), &CPlayer::GetCameraLocked)
		.Prop(_SC("Class"), &CPlayer::GetClass)
		.Prop(_SC("FPS"), &CPlayer::GetFPS)
		.Prop(_SC("ID"), &CPlayer::GetID)
		.Prop(_SC("IP"), &CPlayer::GetIP)
		.Prop(_SC("IsSpawned"), &CPlayer::GetSpawned)
		.Prop(_SC("Key"), &CPlayer::GetKey)
		.Prop(_SC("Name"), &CPlayer::GetName)
		.Prop(_SC("Ping"), &CPlayer::GetPing)
		.Prop(_SC("Spawned"), &CPlayer::GetSpawned)
		.Prop(_SC("StandingOnObject"), &CPlayer::StandingOnObject)
		.Prop(_SC("StandingOnVehicle"), &CPlayer::StandingOnVehicle)
		.Prop(_SC("State"), &CPlayer::GetState)
		.Prop(_SC("Typing"), &CPlayer::Typing)
		.Prop(_SC("UniqueWorld"), &CPlayer::GetUniqueWorld)
		.Prop(_SC("UniqueID"), &CPlayer::GetUniqueID)
		.Prop(_SC("Weapon"), &CPlayer::GetWeapon);

	// Functions
	c.Func(_SC("AddSpeed"), &CPlayer::AddSpeed)
		.Func(_SC("Ban"), &CPlayer::Ban)
		.Func(_SC("Disarm"), &CPlayer::Disarm)
		.Func(_SC("Eject"), &CPlayer::Eject)
		.Func(_SC("GetAmmoAtSlot"), &CPlayer::GetAmmoAtSlot)
		.Func(_SC("GetWeaponAtSlot"), &CPlayer::GetWeaponAtSlot)
		.Func(_SC("GiveMoney"), &CPlayer::GiveMoney)
		.Func(_SC("GiveWeapon"), &CPlayer::GiveWeapon)
		.Func(_SC("Kick"), &CPlayer::Kick)
		.Func(_SC("RemoveWeapon"), &CPlayer::RemoveWeapon)
		.Func(_SC("RemoveMarker"), &CPlayer::RemoveMarker)
		.Func(_SC("RestoreCamera"), &CPlayer::RestoreCamera)
		.Func(_SC("Select"), &CPlayer::Select)
		.Func(_SC("SetAlpha"), &CPlayer::SetAlpha)
		.Overload(_SC("SetAnim"), &CPlayer::Animation)
		.Overload(_SC("SetAnim"), &CPlayer::CompatAnimation)
		.Func(_SC("SetCameraPos"), &CPlayer::SetCameraPos)
		.Func(_SC("SetDrunkLevel"), &CPlayer::SetDrunkLevel)
		.Func(_SC("SetInterior"), &CPlayer::SetInterior)
		.Func(_SC("SetMarker"), &CPlayer::SetMarker)
		.Func(_SC("SetWantedLevel"), &CPlayer::SetWantedLevel)
		.Func(_SC("SetWeapon"), &CPlayer::SetWeapon)
		.Func(_SC("Spawn"), &CPlayer::Spawn)
		.Func(_SC("StreamedToPlayer"), &CPlayer::StreamedToPlayer);

	c.GlobalFunc(_SC("_tostring"), &PlayerToString);
	RootTable(v).Bind( _SC("CPlayer"), c );
}