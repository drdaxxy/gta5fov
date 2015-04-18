This mod allows you to freely set your desired fields of view (first-person walking, driving, aiming, ADS, crouching, and third-person) in Grand Theft Auto V.

Tested and working on the worldwide Steam and retail/Rockstar Warehouse version as of April 18, 2015 - there's no guarantee a future patch won't break it, but this mod will be updated for compatibility if necessary.

Be advised: We do not yet know the game's anti-cheating measures - use at your own risk. This mod modifies game memory and as such looks like a cheat, and may even be considered one in online multiplayer as having a higher field of view can put players at a competitive advantage. I consider it about as risky as SweetFX, so not very, but a risk is still there.

The latest version can always be found at https://github.com/drdaxxy/gta5fov/releases

-------

Installation instructions:

- Find your GTA V installation folder (e.g. C:\Program Files (x86)\Steam\SteamApps\common\Grand Theft Auto V). It should have files such as GTAV.exe and bink2w64.dll in it.
- Extract fov.txt and dsound.dll into that folder.
- Install the Visual C++ 2013 x64 runtime using vcredist_x64.exe if you haven't already.
- Change the contents of fov.ini to your desired vertical(!) fields of view (ADS is aiming down sight). If you only know the horizontal FoV you want, here's a handy calculator: http://www.rjdown.co.uk/projects/bfbc2/fovcalculator.php
- All done! Launch the game as usual.

-------

Anticipated questions / known issues:

Q: I don't see any "dll".
A: Windows doesn't display known file extensions by default - if you just see a "bink2w64" file, that's okay, that's what I meant.

Q: Does this work on the Rockstar Warehouse version of the game too?
A: Yes.

Q: The game refuses to launch when I have the mod installed.
A: Did you install vcredist_x64.exe? The version (2013) is important! Microsoft names all their 64-bit packages, regardless of version, vcredist_x64.exe, so you may have installed one such file before which was older, so you'll still need to install this one.

Q: Okay, but I don't trust you to run a file from you as Administrator.
A: The official download is available at https://www.microsoft.com/en-us/download/details.aspx?id=40784

Q: Why doesn't the FoV slider in the camera menu work anymore?
A: The mod overrides it. If you want the default values back, you can uninstall it. If you want an ingame way of changing field of view, I might try utilising the cheat code prompt for that, but no guarantees.

Q: So how do I uninstall this?
A: Just delete dsound.dll from your GTA V installation folder again.

Q: I have a super fast PC and this doesn't seem to work.
A: The mod waits 30 seconds after the game starts (i.e. the program opens, not 30 seconds after you gain control of your character) to take effect, as it crashes if it tries to load immediately when the game does. I know there's better ways to avoid this, but I wanted to get this out quickly.

Q: I set the FoV to 100 and everything looks weird!
A: You need to convert your FoV to the vertical FoV, see the calculator linked above.

Q: Where's the source code?
A: https://github.com/drdaxxy/gta5fov

Q: Where do I get the latest version?

Q: My question wasn't answered / where can I discuss this?
A: Preferably the Reddit post: http://www.reddit.com/r/GrandTheftAutoV_PC/comments/32n8m0/i_made_a_mod_for_freely_setting_your_firstperson/

-------

Changelog

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