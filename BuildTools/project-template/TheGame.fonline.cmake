# SetupGame option value option value...
# - DEV_NAME (default: "Unknown")
# - NICE_NAME (default: "Unknown")
# - COMPANY_NAME (default: "Unknown")
# - VERSION (default: "0.0.1")
# - ENGINE_VERSION (default: "")
# - MULTIPLAYER_SCRIPTING (default: YES)
# - SINGLEPLAYER_SCRIPTING (default: YES)
# - NATIVE_SCRIPTING (default: YES)
# - ANGELSCRIPT_SCRIPTING (default: YES)
# - MONO_SCRIPTING (default: YES)
# AddContent dir(s)
# AddResources packName dir(s)
# AddRawResources dir(s)
# AddScriptApi headerPath(s)
# AddNativeIncludeDir target dir(s)
# AddNativeSource target pathPattern(s)
# AddAngelScriptSource pathPattern(s)
# AddMonoAssembly assembly
# AddMonoReference assembly target ref(s)
# AddMonoSource assembly target pathPattern(s)
# CreateConfig config inheritenConfig
# TweakConfig config option value
# CreatePackage package config debug
# AddToPackage package binary platform arch packType [customConfig]

SetupGame( DEV_NAME "TheGame"
    NICE_NAME "The Game: Beginning"
    COMPANY_NAME "MyCorpLtd"
    VERSION "0.1.0"
    MULTIPLAYER_SCRIPTING YES
    SINGLEPLAYER_SCRIPTING YES
    NATIVE_SCRIPTING NO )

# Content
AddContent( "Critters" "Items" "Maps" )
AddContent( "Dialogs" )

# Resources
AddResources( "TheGame" "Resources" )

# Scripts
AddScriptApi( "Scripts/MyScriptApi.h" )
AddAngelScriptSource( "Scripts/Test.fos" )
AddMonoAssembly( "TheGame" )
AddMonoReference( "TheGame" "Common" "FOnline" "System" "System.Core" )
AddMonoSource( "TheGame" "Common" "Scripts/Test.cs" )

# Default config
CreateConfig( "Default" "" )
TweakConfig( "Default" "RemoteHost" "1.2.3.4" )
TweakConfig( "Default" "RemotePort" "4013" )

# Test config
CreateConfig( "LocalTest" "Default" )
TweakConfig( "LocalTest" "RemoteHost" "localhost" )
TweakConfig( "LocalTest" "RemotePort" "4014" )
CreateConfig( "LocalWebTest" "LocalTest" )
TweakConfig( "LocalWebTest" "MyOpt" "42" )

# Test builds
CreatePackage( "Test" "LocalTest" YES )
AddToPackage( "Test" "Client" "Windows" "win32" "Raw" )
AddToPackage( "Test" "Client" "Web" "wasm" "Raw" "LocalWebTest" )
AddToPackage( "Test" "Server" "Windows" "win64" "Raw" )
CreatePackage( "ProductionTest" "LocalTest" NO )
AddToPackage( "ProductionTest" "Client" "Windows" "win32" "Raw" )
AddToPackage( "ProductionTest" "Client" "Web" "wasm" "Raw" "LocalWebTest" )
AddToPackage( "ProductionTest" "Server" "Windows" "win64" "Raw" )

AddToPackage( "Test" "Single" "Windows" "win32" "Raw" )

# Production builds
CreatePackage( "Production" "Default" NO )
AddToPackage( "Production" "Client" "Windows" "win32+win64" "Raw" )
AddToPackage( "Production" "Client" "Windows" "win32+win64" "Wix" )
AddToPackage( "Production" "Client" "Windows" "win32" "Zip" )
AddToPackage( "Production" "Client" "Android" "arm+arm64+x86" "Apk" )
AddToPackage( "Production" "Client" "Web" "wasm" "Raw" )
AddToPackage( "Production" "Client" "macOS" "x64" "Bundle" )
AddToPackage( "Production" "Client" "iOS" "arm64" "Bundle" )
AddToPackage( "Production" "Client" "Linux" "x64" "AppImage" )
AddToPackage( "Production" "Server" "Windows" "win64" "Raw" )
AddToPackage( "Production" "Server" "Windows" "win64" "Zip" )
AddToPackage( "Production" "Server" "Linux" "x64" "Raw" )
AddToPackage( "Production" "Server" "Linux" "x64" "Tar" )
AddToPackage( "Production" "Server" "Linux" "x64" "AppImage" )
