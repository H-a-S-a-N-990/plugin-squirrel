#include "Functions.h"

void RegisterGlobals()
{
	// All of the parameter checks have a "t" prepended to account for the root table.
	RootTable(v)

		// Negative parameter counts check if the count is "at least" instead of "exactly equal."
		.Overload(_SC("ClientMessage"), ClientMessage, 6, _SC("tsxiii"))
		.Overload(_SC("ClientMessage"), ClientMessageWithAlpha, 7, _SC("tsxiiii"))
		.Overload(_SC("ClientMessageToAll"), ClientMessageToAll, 5, _SC("tsiii"))
		.Overload(_SC("ClientMessageToAll"), ClientMessageToAllWithAlpha, 6, _SC("tsiiii"))

		.Overload(_SC("Announce"), GameMessage, 4, _SC("tsxi"))
		.Overload(_SC("Announce"), GameMessageAlternate, 3, _SC("tsx"))
		.Overload(_SC("AnnounceAll"), GameMessageToAll, 3, _SC("tsi"))
		.Overload(_SC("AnnounceAll"), GameMessageToAllAlternate, 2, _SC("ts"))

		.Func(_SC("ShutdownServer"), ShutdownServer, 1, _SC("t"))
		.Func(_SC("SetServerName"), SetServerName, 2, _SC("ts"))
		.Func(_SC("SetMaxPlayers"), SetMaxPlayers, 2, _SC("ti"))
		.Func(_SC("SetPassword"), SetServerPassword, 2, _SC("ts"))
		.Func(_SC("SetGameModeName"), SetGameModeText, 2, _SC("ts"))
		.Func(_SC("SetTimeRate"), SetTimeRate, 2, _SC("tn"))
		.Func(_SC("SetHour"), SetHour, 2, _SC("ti"))
		.Func(_SC("SetMinute"), SetMinute, 2, _SC("ti"))
		.Func(_SC("SetTime"), SetTime, 3, _SC("tii"))
		.Func(_SC("SetWeather"), SetWeather, 2, _SC("ti"))
		.Func(_SC("SetGravity"), SetGravity, 2, _SC("tn"))
		.Func(_SC("SetGamespeed"), SetGamespeed, 2, _SC("tn"))
		.Func(_SC("SetWaterLevel"), SetWaterLevel, 2, _SC("tn"))
		.Func(_SC("SetMaxHeight"), SetMaxHeight, 2, _SC("tn"))

		.Func(_SC("GetServerName"), GetServerName, 1, _SC("t"))
		.Func(_SC("GetMaxPlayers"), GetMaxPlayers, 1, _SC("t"))
		.Func(_SC("GetPassword"), GetServerPassword, 1, _SC("t"))
		.Func(_SC("GetGameModeName"), GetGameModeText, 1, _SC("t"))
		.Func(_SC("GetTimeRate"), GetTimeRate, 1, _SC("t"))
		.Func(_SC("GetHour"), GetHour, 1, _SC("t"))
		.Func(_SC("GetMinute"), GetMinute, 1, _SC("t"))
		.Func(_SC("GetWeather"), GetWeather, 1, _SC("t"))
		.Func(_SC("GetGravity"), GetGravity, 1, _SC("t"))
		.Func(_SC("GetGamespeed"), GetGamespeed, 1, _SC("t"))
		.Func(_SC("GetWaterLevel"), GetWaterLevel, 1, _SC("t"))
		.Func(_SC("GetMaxHeight"), GetMaxHeight, 1, _SC("t"))

		.Func(_SC("SetSyncFrameLimiter"), ToggleSyncFrameLimiter, 2, _SC("tb"))
		.Func(_SC("SetFrameLimiter"), ToggleFrameLimiter, 2, _SC("tb"))
		.Func(_SC("SetTaxiBoostJump"), ToggleTaxiBoostJump, 2, _SC("tb"))
		.Func(_SC("SetDriveOnWater"), ToggleDriveOnWater, 2, _SC("tb"))
		.Func(_SC("SetFastSwitch"), ToggleFastSwitch, 2, _SC("tb"))
		.Func(_SC("SetFriendlyFire"), ToggleFriendlyFire, 2, _SC("tb"))
		.Func(_SC("SetDrivebyEnabled"), ToggleDisableDriveby, 2, _SC("tb"))
		.Func(_SC("SetPerfectHandling"), TogglePerfectHandling, 2, _SC("tb"))
		.Func(_SC("SetFlyingCars"), ToggleFlyingCars, 2, _SC("tb"))
		.Func(_SC("SetJumpSwitch"), ToggleJumpSwitch, 2, _SC("tb"))
		.Func(_SC("SetShowOnRadar"), ToggleShowOnRadar, 2, _SC("tb"))
		.Func(_SC("SetShowOnlyTeamMarkers"), ToggleShowOnlyTeamMarkers, 2, _SC("tb"))
		.Func(_SC("SetStuntBike"), ToggleStuntBike, 2, _SC("tb"))
		.Func(_SC("SetShootInAir"), ToggleShootInAir, 2, _SC("tb"))
		.Func(_SC("SetShowNametags"), ToggleShowNametags, 2, _SC("tb"))
		.Func(_SC("SetJoinMessages"), ToggleJoinMessages, 2, _SC("tb"))
		.Func(_SC("SetDeathMessages"), ToggleDeathMessages, 2, _SC("tb"))

		.Func(_SC("GetSyncFrameLimiter"), EnabledSyncFrameLimiter, 1, _SC("t"))
		.Func(_SC("GetFrameLimiter"), EnabledFrameLimiter, 1, _SC("t"))
		.Func(_SC("GetTaxiBoostJump"), EnabledTaxiBoostJump, 1, _SC("t"))
		.Func(_SC("GetDriveOnWater"), EnabledDriveOnWater, 1, _SC("t"))
		.Func(_SC("GetFastSwitch"), EnabledFastSwitch, 1, _SC("t"))
		.Func(_SC("GetFriendlyFire"), EnabledFriendlyFire, 1, _SC("t"))
		.Func(_SC("GetDrivebyEnabled"), EnabledDisableDriveby, 1, _SC("t"))
		.Func(_SC("GetPerfectHandling"), EnabledPerfectHandling, 1, _SC("t"))
		.Func(_SC("GetFlyingCars"), EnabledFlyingCars, 1, _SC("t"))
		.Func(_SC("GetJumpSwitch"), EnabledJumpSwitch, 1, _SC("t"))
		.Func(_SC("GetShowOnRadar"), EnabledShowOnRadar, 1, _SC("t"))
		.Func(_SC("GetShowOnlyTeamMarkers"), EnabledShowOnlyTeamMarkers, 2, _SC("tb"))
		.Func(_SC("GetStuntBike"), EnabledStuntBike, 1, _SC("t"))
		.Func(_SC("GetShootInAir"), EnabledShootInAir, 1, _SC("t"))
		.Func(_SC("GetShowNametags"), EnabledShowNametags, 1, _SC("t"))
		.Func(_SC("GetJoinMessages"), EnabledJoinMessages, 1, _SC("t"))
		.Func(_SC("GetDeathMessages"), EnabledDeathMessages, 1, _SC("t"))

		.Overload(_SC("CreateRadioStream"), CreateRadioStreamWithID)
		.Overload(_SC("CreateRadioStream"), CreateRadioStream)
		.Func(_SC("DestroyRadioStream"), DestroyRadioStream, 2, _SC("ti"))

		.Func(_SC("CreateMarker"), CreateBlip, 6, _SC("tixixi"))
		.Func(_SC("DestroyMarker"), DestroyBlip, 2, _SC("ti"))

		.Overload<void(*)(int, int, Vector *, int, bool)>(_SC("CreateExplosion"), CreateExplosion, 6, _SC("tiixib"))
		.Overload<void(*)(int, int, float, float, float, int, bool)>(_SC("CreateExplosion"), CreateExplosionExpanded, 8, _SC("tiinnnib"))

		.Overload<void(*)(int, int, Vector *)>(_SC("PlaySound"), PlayGameSound, 4, _SC("tiix"))
		.Overload<void(*)(int, int, float, float, float)>(_SC("PlaySound"), PlayGameSoundExpanded, 6, _SC("tiinnn"))

		.Func(_SC("SetUseClasses"), SetUseClasses, 2, _SC("tb"))
		.Func(_SC("UsingClasses"), UsingClasses, 1, _SC("t"))
		.Func(_SC("AddClass"), AddClass, 12, _SC("tixixniiiiii"))

		.Overload<void(*)(Vector *)>(_SC("SetSpawnPlayerPos"), SetSpawnPlayerPos, 2, _SC("tx"))
		.Overload<void(*)(Vector *)>(_SC("SetSpawnCameraPos"), SetSpawnCameraPos, 2, _SC("tx"))
		.Overload<void(*)(Vector *)>(_SC("SetSpawnCameraLook"), SetSpawnCameraLook, 2, _SC("tx"))

		.Overload<void(*)(float, float, float)>(_SC("SetSpawnPlayerPos"), SetSpawnPlayerPosExpanded, 4, _SC("tnnn"))
		.Overload<void(*)(float, float, float)>(_SC("SetSpawnCameraPos"), SetSpawnCameraPosExpanded, 4, _SC("tnnn"))
		.Overload<void(*)(float, float, float)>(_SC("SetSpawnCameraLook"), SetSpawnCameraLookExpanded, 4, _SC("tnnn"))

		.Func(_SC("BanIP"), BanIP, 2, _SC("ts"))
		.Func(_SC("UnbanIP"), UnbanIP, 2, _SC("ts"))
		.Func(_SC("IsIPBanned"), IsIPBanned, 2, _SC("ts"))

		.Func(_SC("GetPlayerIDFromName"), GetPlayerIDFromName, 2, _SC("ts"))
		.Func(_SC("IsWorldCompatibleWithPlayer"), IsWorldCompatibleWithPlayer, 2, _SC("txi"))

		.Func(_SC("CreateSprite"), CreateSprite, 8, _SC("tsiiiini"))
		.Func(_SC("CreateTextdraw"), CreateTextdraw, 5, _SC("tsiii"))

		.Overload(_SC("CreateVehicle"), CreateVehicleCompat)
		.Overload(_SC("CreateVehicle"), CreateVehicle)
		.Overload(_SC("CreateVehicle"), CreateVehicleExpanded)

		.Overload<CPickup * (*)(int, Vector *)>(_SC("CreatePickup"), CreatePickupCompat, 3, _SC("tix"))
		.Overload<CPickup * (*)(int, int, int, Vector *, int, bool)>(_SC("CreatePickup"), CreatePickup, 7, _SC("tiiixib"))
		.Overload<CPickup * (*)(int, int, int, float, float, float, int, bool)>(_SC("CreatePickup"), CreatePickupExpanded, 9, _SC("tiiinnnib"))

		.Overload<CObject * (*)(int, int, Vector *, int)>(_SC("CreateObject"), CreateObject, 5, _SC("tiixi"))
		.Overload<CObject * (*)(int, int, float, float, float, int)>(_SC("CreateObject"), CreateObjectExpanded, 7, _SC("tiinnni"))

		.Func(_SC("FindPickup"), FindPickup, 2, _SC("ti"))
		.Func(_SC("FindObject"), FindObject, 2, _SC("ti"))
		.Func(_SC("FindVehicle"), FindVehicle, 2, _SC("ti"))

		.Func(_SC("SetWorldBounds"), SetWorldBounds, 5, _SC("tnnnn"))
		.Func(_SC("GetWorldBounds"), GetWorldBounds, 1, _SC("t"))

		.Func(_SC("SetWastedSettings"), SetWastedSettings, 8, _SC("tnnnnxnn"))
		.Func(_SC("GetWastedSettings"), GetWastedSettings, 1, _SC("t"))
		.Func(_SC("SetKillDelay"), SetKillDelay, 2, _SC("ti"))
		.Func(_SC("GetKillDelay"), GetKillDelay, 1, _SC("t"))

		.Func(_SC("RawHideMapObject"), RawHideMapObject, 5, _SC("tiiii"))
		.Func(_SC("HideMapObject"), HideMapObject, 5, _SC("tifff"))
		.Func(_SC("ShowMapObject"), ShowMapObject, 5, _SC("tifff"))
		.Func(_SC("ShowAllMapObjects"), ShowAllMapObjects, 1, _SC("t"))

		.Func(_SC("ForceAllSelect"), ForceAllSelect, 1, _SC("t"))

		.Func(_SC("ResetAllVehicleHandling"), ResetAllVehicleHandling, 1, _SC("t"))
		.Func(_SC("IsHandlingRuleSet"), IsHandlingRuleSet, 3, _SC("tii"))
		.Func(_SC("SetHandlingRule"), SetHandlingRule, 4, _SC("tiif"))
		.Func(_SC("GetHandlingRule"), GetHandlingRule, 3, _SC("tii"))
		.Func(_SC("ResetHandlingRule"), ResetHandlingRule, 3, _SC("tii"))
		.Func(_SC("ResetVehicleHandling"), ResetVehicleHandling, 2, _SC("ti"))

		// Compatibility functions
		.Func(_SC("GetCinematicBorder"), GetCinematicBorder, 2, _SC("tx"))
		.Func(_SC("GetGreenScanLines"), GetGreenScanLines, 2, _SC("tx"))
		.Func(_SC("GetWhiteScanLines"), GetWhiteScanLines, 2, _SC("tx"))
		.Func(_SC("SetCinematicBorder"), SetCinematicBorder, 3, _SC("txb"))
		.Func(_SC("SetGreenScanLines"), SetGreenScanLines, 3, _SC("txb"))
		.Func(_SC("SetWhiteScanLines"), SetWhiteScanLines, 3, _SC("txb"))
		.Func(_SC("KickPlayer"), KickPlayer, 2, _SC("tx"))
		.Func(_SC("BanPlayer"), BanPlayer, 2, _SC("tx"))
		.Func(_SC("Message"), Message, 2, _SC("ts"))
		.Func(_SC("MessagePlayer"), MessagePlayer, 3, _SC("tsx"))
		.Func(_SC("MessageAllExcept"), MessageAllExcept, 3, _SC("tsx"))
		.Func(_SC("PrivMessage"), PrivMessage, 3, _SC("txs"))
		.Func(_SC("PrivMessageAll"), PrivMessageAll, 2, _SC("ts"))
		.Func(_SC("SendPlayerMessage"), SendPlayerMessage, 4, _SC("txxs"))

		.Func(_SC("GetWeaponName"), GetWeaponName, 2, _SC("ti"))
		.Func(_SC("GetDistrictName"), GetDistrictName, 3, _SC("tff"))
		.Func(_SC("GetSkinName"), GetSkinName, 2, _SC("ti"))
		.Func(_SC("GetWeaponID"), GetWeaponID, 2, _SC("ts"))
		.Func(_SC("GetSkinID"), GetSkinID, 2, _SC("ts"))
		.Func(_SC("GetTickCount"), SQGetTickCount, 1, _SC("t"))

		.Func(_SC("SetWeaponDataValue"), SetWeaponDataValue, 4, _SC("tiin"))
		.Func(_SC("GetWeaponDataValue"), GetWeaponDataValue, 3, _SC("tii"))
		.Func(_SC("ResetWeaponDataValue"), ResetWeaponDataValue, 3, _SC("tii"))
		.Func(_SC("IsWeaponDataModified"), IsWeaponDataModified, 3, _SC("tii"))
		.Func(_SC("ResetWeaponData"), ResetWeaponData, 2, _SC("ti"))
		.Func(_SC("ResetAllWeaponData"), ResetAllWeaponData, 1, _SC("t"))

		.Func(_SC("DistanceFromPoint"), DistanceFromPoint, 5, _SC("tffff"))
		.Func(_SC("ReloadScripts"), ReloadScripts, 1, _SC("t"))

		.Func(_SC("GetVehicleModelFromName"), GetVehicleModelFromName, 2, _SC("ts"))
		.Func(_SC("GetVehicleNameFromModel"), GetVehicleNameFromModel, 2, _SC("ti"))
		.Func(_SC("IsNum"), IsNum, 2, _SC("ts"))

		.Func(_SC("GetVehicleCount"), GetVehicleCount, 1, _SC("t"))
		.Func(_SC("GetPickupCount"), GetPickupCount, 1, _SC("t"))
		.Func(_SC("GetObjectCount"), GetObjectCount, 1, _SC("t"))
		.Func(_SC("GetPlayers"), GetPlayers, 1, _SC("t"))

		.Func(_SC("GetFallEnabled"), GetFallEnabled, 1, _SC("t"))
		.Func(_SC("SetFallEnabled"), SetFallEnabled, 2, _SC("tb"))
		.Func(_SC("GetDeathmatchScoreboard"), GetDeathmatchScoreboard, 1, _SC("t"))
		.Func(_SC("SetDeathmatchScoreboard"), SetDeathmatchScoreboard, 2, _SC("tb"))
		.Func(_SC("GetWeaponSync"), GetWeaponSync, 2, _SC("ti"))
		.Func(_SC("SetWeaponSync"), SetWeaponSync, 3, _SC("tib"))
		.Func(_SC("SetWeatherLock"), SetWeatherLock, 2, _SC("tb"))
		.Func(_SC("GetWeatherLock"), GetWeatherLock, 1, _SC("t"))

		.Func(_SC("GetTime"), GetTime, 1, _SC("t"))
		.Func(_SC("GetFullTime"), GetFullTime, 1, _SC("t"))
		.Func(_SC("LoadModule"), LoadVCMPModule, 2, _SC("ts"))

		.Func(_SC("GetVehiclesForcedRespawnHeight"), GetVehiclesForcedRespawnHeight, 1, _SC("t"))
		.Func(_SC("SetVehiclesForcedRespawnHeight"), SetVehiclesForcedRespawnHeight, 2, _SC("tn"))

		.SquirrelFunc(_SC("FindPlayer"), FindPlayer)
		.SquirrelFunc(_SC("NewTimer"), NewTimer)
		.SquirrelFunc(_SC("InPoly"), InPoly)

		.SquirrelFunc(_SC("SetAmmuWeapon"), SetAmmuWeapon)
		.SquirrelFunc(_SC("IsAmmuWeaponEnabled"), IsAmmuWeaponEnabled)
		.SquirrelFunc(_SC("SetAmmuWeaponEnabled"), SetAmmuWeaponEnabled)

		.Func(_SC("BindKey"), BindKey, -3, _SC("tbi"))
		.Func(_SC("UnbindKey"), RemoveKeybind, 2, _SC("ti"))
		.Func(_SC("UnbindAll"), RemoveAllKeybinds, 1, _SC("t"));
}

void RegisterConstants()
{
	ConstTable(v)
		.Const(_SC("WEP_FIST"), 0)
		.Const(_SC("WEP_BRASSKNUCKLES"), 1)
		.Const(_SC("WEP_SCREWDRIVER"), 2)
		.Const(_SC("WEP_GOLFCLUB"), 3)
		.Const(_SC("WEP_NIGHTSTICK"), 4)
		.Const(_SC("WEP_KNIFE"), 5)
		.Const(_SC("WEP_BASEBALLBAT"), 6)
		.Const(_SC("WEP_HAMMER"), 7)
		.Const(_SC("WEP_MEATCLEAVER"), 8)
		.Const(_SC("WEP_MACHETE"), 9)
		.Const(_SC("WEP_KATANA"), 10)
		.Const(_SC("WEP_CHAINSAW"), 11)
		.Const(_SC("WEP_GRENADE"), 12)
		.Const(_SC("WEP_REMOTE"), 13)
		.Const(_SC("WEP_TEARGAS"), 14)
		.Const(_SC("WEP_MOLOTOV"), 15)
		.Const(_SC("WEP_ROCKET"), 16)
		.Const(_SC("WEP_COLT"), 17)
		.Const(_SC("WEP_COLT45"), 17)
		.Const(_SC("WEP_PYTHON"), 18)
		.Const(_SC("WEP_SHOTGUN"), 19)
		.Const(_SC("WEP_SPAZ"), 20)
		.Const(_SC("WEP_SPAS12"), 20)
		.Const(_SC("WEP_STUBBY"), 21)
		.Const(_SC("WEP_TEC9"), 22)
		.Const(_SC("WEP_UZI"), 23)
		.Const(_SC("WEP_INGRAM"), 24)
		.Const(_SC("WEP_MP5"), 25)
		.Const(_SC("WEP_M4"), 26)
		.Const(_SC("WEP_RUGER"), 27)
		.Const(_SC("WEP_SNIPER"), 28)
		.Const(_SC("WEP_LASERSCOPE"), 29)
		.Const(_SC("WEP_ROCKETLAUNCHER"), 30)
		.Const(_SC("WEP_RPG"), 30)
		.Const(_SC("WEP_FLAMETHROWER"), 31)
		.Const(_SC("WEP_M60"), 32)
		.Const(_SC("WEP_MINIGUN"), 33)

		.Const(_SC("WEP_BOMB"), 34)
		.Const(_SC("WEP_HELICANNON"), 35)
		.Const(_SC("WEP_CAMERA"), 36)
		.Const(_SC("WEP_VEHICLE"), 39)
		.Const(_SC("WEP_DRIVEBY"), 42)
		.Const(_SC("WEP_DROWNED"), 43)
		.Const(_SC("WEP_FALL"), 44)
		.Const(_SC("WEP_EXPLOSION"), 51)
		.Const(_SC("WEP_SUICIDE"), 70)

		.Const(_SC("WEATHER_MOSTLYCLEAR"), 0)
		.Const(_SC("WEATHER_OVERCAST"), 1)
		.Const(_SC("WEATHER_THUNDERSTORM"), 2)
		.Const(_SC("WEATHER_STORM"), 2)
		.Const(_SC("WEATHER_STORMY"), 2)
		.Const(_SC("WEATHER_FOGGY"), 3)
		.Const(_SC("WEATHER_FOG"), 3)
		.Const(_SC("WEATHER_CLEAR"), 4)
		.Const(_SC("WEATHER_SUNNY"), 4)
		.Const(_SC("WEATHER_RAIN"), 5)
		.Const(_SC("WEATHER_RAINY"), 5)
		.Const(_SC("WEATHER_DARKCLOUDY"), 6)
		.Const(_SC("WEATHER_LIGHTCLOUDY"), 7)
		.Const(_SC("WEATHER_OVERCASTCLOUDY"), 8)
		.Const(_SC("WEATHER_BLACKCLOUDS"), 9)

		.Const(_SC("VEH_LANDSTALKER"), 130)
		.Const(_SC("VEH_IDAHO"), 131)
		.Const(_SC("VEH_STINGER"), 132)
		.Const(_SC("VEH_LINERUNNER"), 133)
		.Const(_SC("VEH_PERENNIAL"), 134)
		.Const(_SC("VEH_SENTINEL"), 135)
		.Const(_SC("VEH_RIO"), 136)
		.Const(_SC("VEH_FIRETRUCK"), 137)
		.Const(_SC("VEH_TRASHMASTER"), 138)
		.Const(_SC("VEH_STRETCH"), 139)
		.Const(_SC("VEH_MANANA"), 140)
		.Const(_SC("VEH_INFERNUS"), 141)
		.Const(_SC("VEH_VOODOO"), 142)
		.Const(_SC("VEH_PONY"), 143)
		.Const(_SC("VEH_MULE"), 144)
		.Const(_SC("VEH_CHEETAH"), 145)
		.Const(_SC("VEH_AMBULANCE"), 146)
		.Const(_SC("VEH_FBIWASHINGTON"), 147)
		.Const(_SC("VEH_MOONBEAM"), 148)
		.Const(_SC("VEH_ESPERANTO"), 149)
		.Const(_SC("VEH_TAXI"), 150)
		.Const(_SC("VEH_WASHINGTON"), 151)
		.Const(_SC("VEH_BOBCAT"), 152)
		.Const(_SC("VEH_MRWHOOPEE"), 153)
		.Const(_SC("VEH_BFINJECTION"), 154)
		.Const(_SC("VEH_HUNTER"), 155)
		.Const(_SC("VEH_POLICE"), 156)
		.Const(_SC("VEH_ENFORCER"), 157)
		.Const(_SC("VEH_SECURICAR"), 158)
		.Const(_SC("VEH_BANSHEE"), 159)
		.Const(_SC("VEH_PREDATOR"), 160)
		.Const(_SC("VEH_BUS"), 161)
		.Const(_SC("VEH_RHINO"), 162)
		.Const(_SC("VEH_BARRACKSOL"), 163)
		.Const(_SC("VEH_BARRACKS"), 163)
		.Const(_SC("VEH_CUBANHERMES"), 164)
		.Const(_SC("VEH_HELICOPTER"), 165)
		.Const(_SC("VEH_ANGEL"), 166)
		.Const(_SC("VEH_COACH"), 167)
		.Const(_SC("VEH_CABBIE"), 168)
		.Const(_SC("VEH_STALLION"), 169)
		.Const(_SC("VEH_RUMPO"), 170)
		.Const(_SC("VEH_RCBANDIT"), 171)
		.Const(_SC("VEH_HEARSE"), 172)
		.Const(_SC("VEH_PACKER"), 173)
		.Const(_SC("VEH_SENTINELXS"), 174)
		.Const(_SC("VEH_ADMIRAL"), 175)
		.Const(_SC("VEH_SQUALO"), 176)
		.Const(_SC("VEH_SEASPARROW"), 177)
		.Const(_SC("VEH_PIZZABOY"), 178)
		.Const(_SC("VEH_GANGBURRITO"), 179)
		.Const(_SC("VEH_AIRTRAIN"), 180)
		.Const(_SC("VEH_DEADDODO"), 181)
		.Const(_SC("VEH_SPEEDER"), 182)
		.Const(_SC("VEH_REEFER"), 183)
		.Const(_SC("VEH_TROPIC"), 184)
		.Const(_SC("VEH_FLATBED"), 185)
		.Const(_SC("VEH_YANKEE"), 186)
		.Const(_SC("VEH_CADDY"), 187)
		.Const(_SC("VEH_ZEBRA"), 188)
		.Const(_SC("VEH_ZEBRACAB"), 188)
		.Const(_SC("VEH_TOPFUN"), 189)
		.Const(_SC("VEH_SKIMMER"), 190)
		.Const(_SC("VEH_PCJ600"), 191)
		.Const(_SC("VEH_PCJ"), 191)
		.Const(_SC("VEH_FAGGIO"), 192)
		.Const(_SC("VEH_FREEWAY"), 193)
		.Const(_SC("VEH_RCBARON"), 194)
		.Const(_SC("VEH_RCRAIDER"), 195)
		.Const(_SC("VEH_GLENDALE"), 196)
		.Const(_SC("VEH_OCEANIC"), 197)
		.Const(_SC("VEH_SANCHEZ"), 198)
		.Const(_SC("VEH_SPARROW"), 199)
		.Const(_SC("VEH_PATRIOT"), 200)
		.Const(_SC("VEH_LOVEFIST"), 201)
		.Const(_SC("VEH_COASTGUARD"), 202)
		.Const(_SC("VEH_DINGHY"), 203)
		.Const(_SC("VEH_HERMES"), 204)
		.Const(_SC("VEH_SABRE"), 205)
		.Const(_SC("VEH_SABRETURBO"), 206)
		.Const(_SC("VEH_PHOENIX"), 207)
		.Const(_SC("VEH_WALTON"), 208)
		.Const(_SC("VEH_REGINA"), 209)
		.Const(_SC("VEH_COMET"), 210)
		.Const(_SC("VEH_DELUXO"), 211)
		.Const(_SC("VEH_BURRITO"), 212)
		.Const(_SC("VEH_SPANDEX"), 213)
		.Const(_SC("VEH_SPANDEXPRESS"), 213)
		.Const(_SC("VEH_MARQUIS"), 214)
		.Const(_SC("VEH_BAGGAGE"), 215)
		.Const(_SC("VEH_BAGGAGEHANDLER"), 215)
		.Const(_SC("VEH_KAUFMAN"), 216)
		.Const(_SC("VEH_KAUFMANCAB"), 216)
		.Const(_SC("VEH_MAVERICK"), 217)
		.Const(_SC("VEH_VCNMAVERICK"), 218)
		.Const(_SC("VEH_RANCHER"), 219)
		.Const(_SC("VEH_FBIRANCHER"), 220)
		.Const(_SC("VEH_VIRGO"), 221)
		.Const(_SC("VEH_GREENWOOD"), 222)
		.Const(_SC("VEH_CUBANJETMAX"), 223)
		.Const(_SC("VEH_HOTRING1"), 224)
		.Const(_SC("VEH_HOTRINGRACER1"), 224)
		.Const(_SC("VEH_SANDKING"), 225)
		.Const(_SC("VEH_BLISTA"), 226)
		.Const(_SC("VEH_BLISTAC"), 226)
		.Const(_SC("VEH_BLISTACOMPACT"), 226)
		.Const(_SC("VEH_COMPACT"), 226)
		.Const(_SC("VEH_POLICEMAV"), 227)
		.Const(_SC("VEH_POLICEMAVERICK"), 227)
		.Const(_SC("VEH_BOXVILLE"), 228)
		.Const(_SC("VEH_BENSON"), 229)
		.Const(_SC("VEH_MESA"), 230)
		.Const(_SC("VEH_MESAGRANDE"), 230)
		.Const(_SC("VEH_RCGOBLIN"), 231)
		.Const(_SC("VEH_HOTRING2"), 232)
		.Const(_SC("VEH_HOTRINGRACER2"), 232)
		.Const(_SC("VEH_HOTRING3"), 233)
		.Const(_SC("VEH_HOTRINGRACER3"), 233)
		.Const(_SC("VEH_BLOODRING1"), 234)
		.Const(_SC("VEH_BLOODRINGBANGER1"), 234)
		.Const(_SC("VEH_BLOODRING2"), 235)
		.Const(_SC("VEH_BLOODRINGBANGER2"), 235)
		.Const(_SC("VEH_VICECHEE"), 236)
		.Const(_SC("VEH_POLICECHEETAH"), 236)
		.Const(_SC("VEH_FBICHEETAH"), 236)
		.Const(_SC("VEH_CHEETAH2"), 236)

		.Const(_SC("UPDATE_PLAYER_ONFOOT"), 0)
		.Const(_SC("UPDATE_PLAYER_FOOT"), 0)
		.Const(_SC("UPDATE_PLAYER_AIM"), 1)
		.Const(_SC("UPDATE_PLAYER_DRIVER"), 2)
		.Const(_SC("UPDATE_PLAYER_PASSENGER"), 3)

		.Const(_SC("UPDATE_VEHICLE_DRIVER"), 0)
		.Const(_SC("UPDATE_VEHICLE_OTHER"), 1)

		.Const(_SC("BODYPART_BODY"), 0)
		.Const(_SC("BODYPART_TORSO"), 1)
		.Const(_SC("BODYPART_LEFTARM"), 2)
		.Const(_SC("BODYPART_LARM"), 2)
		.Const(_SC("BODYPART_RIGHTARM"), 3)
		.Const(_SC("BODYPART_RARM"), 3)
		.Const(_SC("BODYPART_LEFTLEG"), 4)
		.Const(_SC("BODYPART_LLEG"), 4)
		.Const(_SC("BODYPART_RIGHTLEG"), 5)
		.Const(_SC("BODYPART_RLEG"), 5)
		.Const(_SC("BODYPART_HEAD"), 6)

		.Const(_SC("PARTREASON_QUIT"), 1)
		.Const(_SC("PARTREASON_DISCONNECTED"), 1)
		.Const(_SC("PARTREASON_TIMEOUT"), 0)
		.Const(_SC("PARTREASON_KICKEDBANNED"), 2)
		.Const(_SC("PARTREASON_KICKED"), 2)
		.Const(_SC("PARTREASON_BANNED"), 2)
		.Const(_SC("PARTREASON_CRASHED"), 3)

		.Const(_SC("KEY_ONFOOT_FORWARD"), 32768)
		.Const(_SC("KEY_ONFOOT_BACKWARD"), 16384)
		.Const(_SC("KEY_ONFOOT_LEFT"), 8192)
		.Const(_SC("KEY_ONFOOT_RIGHT"), 4096)
		.Const(_SC("KEY_ONFOOT_JUMP"), 2176)
		.Const(_SC("KEY_ONFOOT_SPRINT"), 1024)
		.Const(_SC("KEY_ONFOOT_FIRE"), 576)
		.Const(_SC("KEY_ONFOOT_CROUCH"), 288)
		.Const(_SC("KEY_ONFOOT_PUNCH"), 64)
		.Const(_SC("KEY_ONFOOT_NEXTWEP"), 2)
		.Const(_SC("KEY_ONFOOT_PREVWEP"), 4)
		.Const(_SC("KEY_ONFOOT_AIM"), 1)

		.Const(_SC("KEY_INCAR_LEFT"), 8192)
		.Const(_SC("KEY_INCAR_RIGHT"), 4096)
		.Const(_SC("KEY_INCAR_BACKWARD"), 2176)
		.Const(_SC("KEY_INCAR_FORWARD"), 1024)
		.Const(_SC("KEY_INCAR_HORN"), 288)
		.Const(_SC("KEY_INCAR_LEANUP"), 16)
		.Const(_SC("KEY_INCAR_LEANDOWN"), 8)
		.Const(_SC("KEY_INCAR_LOOKLEFT"), 4)
		.Const(_SC("KEY_INCAR_LOOKRIGHT"), 2)

		.Const(_SC("SQUIRREL_VERSION"), 399); // 0.4-squirrel version 3.99 (up to 4.00 on final release)
}
