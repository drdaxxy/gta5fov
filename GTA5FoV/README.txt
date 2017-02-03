This mod allows you to freely set your desired fields of view (first-person walking, driving, aiming, ADS, crouching, and third-person) in Grand Theft Auto V.

Tested and working on the worldwide Steam and retail/Rockstar Warehouse version as of February 3, 2017 - there's no guarantee a future patch won't break it, but this mod will be updated for compatibility if necessary.

Be advised: We do not yet know the game's anti-cheating measures - use at your own risk. This mod modifies game memory and as such looks like a cheat, and may even be considered one in online multiplayer as having a higher field of view can put players at a competitive advantage. I consider it about as risky as SweetFX, so not very, but a risk is still there.

The latest version can always be found at https://github.com/drdaxxy/gta5fov/releases

-------

Installation instructions:

- Find your GTA V installation folder (e.g. C:\Program Files (x86)\Steam\SteamApps\common\Grand Theft Auto V). It should have files such as GTAV.exe and bink2w64.dll in it.
- Extract fov.ini and dsound.dll into that folder.
- Install the Visual C++ 2015 Update 3(!) x64 runtime using vcredist_x64.exe if you haven't already.
- Change the contents of fov.ini to your desired vertical(!) fields of view (ADS is aiming down sight). If you only know the horizontal FoV you want, here's a handy calculator: http://www.rjdown.co.uk/projects/bfbc2/fovcalculator.php
- All done! Launch the game as usual.

-------

Anticipated questions / known issues:

Q: How do I use this with Alexander Blade's ASI loader?
A:
- Install the FoV mod as normal.
- Install ASI loader's dsound.dll but rename it to, for example, asiloader.dll
- Open fov.ini
- Uncomment the "ProxyLibrary" line (remove the semicolon at the start of it) and change "other_dsound.dll" to "asiloader.dll"
- Save fov.ini
The crucial part here is that the file named dsound.dll in your GTA folder should still be the FoV mod. The other mod needs to have a different name. That doesn't have to be asiloader.dll, of course, you can use whatever name you want, but you'll need to adjust the ProxyLibrary parameter in fov.ini accordingly.

Q: I don't see any "dll".
A: Windows doesn't display known file extensions by default - if you just see a "bink2w64" file, that's okay, that's what I meant.

Q: Does this work on the Rockstar Warehouse version of the game too?
A: Yes.

Q: The game refuses to launch when I have the mod installed.
A: Did you install vcredist_x64.exe? The version (2015 Update 3) is important! Microsoft names all their 64-bit packages, regardless of version, vcredist_x64.exe, so you may have installed one such file before which was older, so you'll still need to install this one.
!!! THIS WAS UPDATED SINCE THE LAST FOV MOD RELEASE !!!

Q: Okay, but I don't trust you to run a file from you as Administrator.
A: The official download is available at https://www.microsoft.com/en-us/download/details.aspx?id=53587

Q: Why doesn't the FoV slider in the camera menu work anymore?
A: The mod overrides it. If you want the default values back, you can uninstall it. If you want an ingame way of changing field of view, I might try utilising the cheat code prompt for that, but no guarantees.

Q: So how do I uninstall this?
A: Just delete dsound.dll from your GTA V installation folder again.

Q: I don't want the mod to change all fields of view, how do I disable only some changes?
A: Edit the fov.ini file and comment out the line (add a ; in front of it).

Q: I have a super fast PC and this doesn't seem to work.
A: The mod waits 30 seconds after the game starts (i.e. the program opens, not 30 seconds after you gain control of your character) to take effect, as it crashes if it tries to load immediately when the game does. I know there's better ways to avoid this, but I wanted to get this out quickly.

Q: I set the FoV to 100 and everything looks weird!
A: You need to convert your FoV to the vertical FoV, see the calculator linked above.

Q: Where's the source code?
A: https://github.com/drdaxxy/gta5fov

Q: Where do I get the latest version?
A: https://github.com/drdaxxy/gta5fov/releases

Q: My question wasn't answered / where can I discuss this?
A: The Reddit post: http://www.reddit.com/r/GrandTheftAutoV_PC/comments/32n8m0/i_made_a_mod_for_freely_setting_your_firstperson/ or preferably the issue tracker on GitHub.

-------

Changelog

1.34 (February 3, 2017)
- (internal) probably update MSVC version again
***This means you need the 2015 Update 3 redistributable now.***
- Update signatures, fix mod for latest patch (fixes #14)

1.33 (October 11, 2016)
- (internal) Update MSVC version (because I don't have 2013 installed anymore).
***This means you need the 2015 redistributable now.***
- Update signatures, fix mod for latest patch (fixes #13)

1.32 (December 17, 2015)
- Update signatures, fix mod for latest patch (fixes #10)

1.31 (June 12, 2015)
- Update signatures, fix mod for latest patch (fixes #6)

1.3 (April 18, 2015)
- Support disabling individual FoV mods by commenting out
- Support chain-loading other dsound.dll wrappers
- Disable third-person FoV mod by default (some people are reporting issues)

1.2 (April 18, 2015)
- Polished and released source
- Switched to INI for configuration
- Added aiming, driving, crouching, ADS and third-person settings

1.11 (April 15, 2015)
- Bundled vcredist_x64.exe

1.1 (April 15, 2015)
- Added debug log output.
- Changed wrapped DLL to dsound.dll for compatibility with non-Steam version.

1.0 (April 15, 2015)
- Initial release
