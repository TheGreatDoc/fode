#tento soubor p�elo�il Mawerick - megaboy@iol.cz, http://rpg.game-star.cz
#############################################################
#  Message File: Door.msg                                   #
#                                                           #
#  Note: Characters within curly braces (like line 100)     #
#        will be read in as a message string. Caution       #
#        should be used when making comments. All comments  #
#        should be prepended with a pound symbol for        #
#        visual ease. This does not comment out the line    #
#        though.                                            #
#                                                           #
#  Purpose: This message file contains the information      #
#           concerning doors in a locked state, trapped     #
#           state, locked and trapped state.                #
#                                                           #
#  Log: Please note any changes that have been made to this #
#       file and comment which lines have changed.          #
#       April 19,1998 nbk: added message line to be used    #
#                          for doors opened with keys.      #
#                                                           #
#  Created: September 26, 1997                              #
#                                                           #
#  Updated:                                                 #
#############################################################

#############################################################
#  The following lines are for description of the door. The #
#  first lines, line 100-1, are for the look_at_proc. The   #
#  remainder until the next block are for description_proc  #
#  based one skill and perception success.                  #
#############################################################

# look_at_proc
{100}{}{Vid� d�ev�n� dve�e.}
{101}{}{Vid� �elezn� dve�e.}

# description_proc

# Perception Check Critical Success
{102}{}{Vid� pevn� dve�e se z�mkem, odemykateln�m pomoc� pakl���, a s vysoce v�bu�nou past� um�st�nou na z�rubni dve��, kterou se m��e� pokusit odstranit.}
{103}{}{Vid� pevn� dve�e se z�mkem a vysoce v�bu�nou past� um�st�nou na z�rubni dve��, kterou se m��e� pokusit odstranit.}
{104}{}{Vid� pevn� dve�e bez zjevn�ho zamykac�ho za��zen� a vysoce v�bu�nou past� um�st�nou na z�rubni dve��, kterou se m��e� pokusit odstranit.}
{105}{}{Vid� pevn� dve�e se star�m, rezav�m z�mkem a vysoce v�bu�nou past� um�st�nou na z�rubni dve��, kterou se m��e� pokusit odstranit.}

{106}{}{Vid� pevn� dve�e se z�mkem (m��e b�t odem�en pomoc� pakl���) a past� um�st�nou na z�rubni dve��, kterou se m��e� pokusit odstranit.}
{107}{}{Vid� pevn� dve�e se z�mkem a past� um�st�nou na z�rubni dve��, kterou se m��e� pokusit odstranit.}
{108}{}{Vid� pevn� dve�e bez zjevn�ho zamykac�ho za��zen� a past� um�st�nou na z�rubni dve��, kterou se m��e� pokusit odstranit.}
{109}{}{Vid� pevn� dve�e se star�m, rezav�m z�mkem a past� um�st�nou na z�rubni dve��, kterou se m��e� pokusit odstranit.}

{110}{}{Vid� pevn� dve�e se z�mkem, odemykateln�m sadou pakl���, a kousek dr�tku, jen� �ouh� ze z�rubn� dve��. M��e� se pokusit je vyp��it.}
{111}{}{Vid� pevn� dve�e se z�mkem a kousek dr�tku, jen� �ouh� ze z�rubn� dve��. M��e� se pokusit je vyp��it.}
{112}{}{Vid� pevn� dve�e bez zjevn�ho zamykac�ho za��zen� a kousek dr�tku, jen� �ouh� ze z�rubn� dve��. M��e� se pokusit je vyp��it.}
{113}{}{Vid� pevn� dve�e se star�m, rezav�m z�mkem a kousek dr�tku, jen� �ouh� ze z�rubn� dve��. M��e� se pokusit je vyp��it.}

{114}{}{Vid� pevn� dve�e se z�mkem (odemykateln�m sadou pakl���), kter� se m��e� pokusit vyp��it.}
{115}{}{Vid� pevn� dve�e se z�mkem, kter� se m��e� pokusit vyp��it.}
{116}{}{Vid� pevn� dve�e bez zjevn�ho zamykac�ho za��zen�, kter� se m��e� pokusit vyp��it.}
{117}{}{Vid� pevn� dve�e se star�m, rezav�m z�mkem, kter� se m��e� pokusit vyp��it.}

# Perception Check Success

{118}{}{Vid� pevn� dve�e se z�mkem, odemykateln�m pomoc� pakl���, a vysoce v�bu�nou past� um�st�nou na z�rubni dve��.}
{119}{}{Vid� pevn� dve�e se z�mkem a vysoce v�bu�nou past� um�st�nou na z�rubni dve��.}
{120}{}{Vid� pevn� dve�e bez zjevn�ho zamykac�ho za��zen� a vysoce v�bu�nou past� um�st�nou na z�rubni dve��.}
{121}{}{Vid� pevn� dve�e se star�m, rezav�m z�mkem a vysoce v�bu�nou past� um�st�nou na z�rubni dve��.}

{122}{}{Vid� pevn� dve�e se z�mkem (odemykateln�m sadou pakl���) a past� um�st�nou na z�rubni dve��.}
{123}{}{Vid� pevn� dve�e se z�mkem a past� um�st�nou na z�rubni dve��.}
{124}{}{Vid� pevn� dve�e bez zjevn�ho zamykac�ho za��zen� a past� um�st�nou na z�rubni dve��.}
{125}{}{Vid� pevn� dve�e se star�m a rezav�m z�mkem a past� um�st�nou na z�rubni dve��.}

{126}{}{Vid� pevn� dve�e se z�mkem (odemykateln� pomoc� pakl���) a kousek dr�tku, jen� �ouh� ze z�rubn� dve��.}
{127}{}{Vid� pevn� dve�e se z�mkem a kousek dr�tku, jen� �ouh� ze z�rubn� dve��.}
{128}{}{Vid� pevn� dve�e bez zjevn�ho zamykac�ho za��zen� a kousek dr�tku, jen� �ouh� ze z�rubn� dve��.}
{129}{}{Vid� pevn� dve�e se star�m, rezav�m z�mkem a kousek dr�tku, jen� �ouh� ze z�rubn� dve��.}

{130}{}{Vid� pevn� dve�e se z�mkem, kter� m��e� odemknout pomoc� pakl���.}
{131}{}{Vid� pevn� dve�e se z�mkem.}
{132}{}{Vid� pevn� dve�e bez zjevn�ho odemykac�ho za��zen�.}
{133}{}{Vid� pevn� dve�e se star�m, rezav�m z�mkem.}

# Perception Check Critical Failure

{134}{}{Vid� poni�en� dve�e se z�mkem, kter� m��e� odemknout pomoc� pakl���, a vysoce v�bu�nou past� um�st�nou na z�rubni dve��.}
{135}{}{Vid� poni�en� dve�e se z�mkem a vysoce v�bu�nou past� um�st�nou na z�rubni dve��.}
{136}{}{Vid� poni�en� dve�e bez zjevn�ho odemykac�ho za��zen� a vysoce v�bu�nou past� um�st�nou na z�rubni dve��.}
{137}{}{Vid� poni�en� dve�e se star�m, rezav�m z�mkem a vysoce v�bu�nou past� um�st�nou na z�rubni dve��.}

{138}{}{Vid� poni�en� dve�e se z�mkem, kter� m��e� odemknout pomoc� pakl���, a past� um�st�nou na z�rubni dve��.}
{139}{}{Vid� poni�en� dve�e se z�mkem a past� um�st�nou na z�rubni dve��.}
{140}{}{Vid� poni�en� dve�e bez zjevn�ho odemykac�ho za��zen� a past� um�st�nou na z�rubni dve��.}
{141}{}{Vid� poni�en� dve�e se star�m, rezav�m z�mkem a past� um�st�nou na z�rubni dve��.}

{142}{}{Vid� poni�en� dve�e se z�mkem, kter� m��e� odemknout pomoc� pakl���, a kousek dr�tku, jen� �ouh� ze z�rubn� dve��.}
{143}{}{Vid� poni�en� dve�e se z�mkem a kousek dr�tku, jen� �ouh� ze z�rubn� dve��.}
{144}{}{Vid� poni�en� dve�e bez zjevn�ho odemykac�ho za��zen� a kousek dr�tku, jen� �ouh� ze z�rubn� dve��.}
{145}{}{Vid� poni�en� dve�e se star�m, rezav�m z�mkem a kousek dr�tku, jen� �ouh� ze z�rubn� dve��.}

{146}{}{Vid� poni�en� dve�e se z�mkem, kter� m��e� odemknout pomoc� pakl���.}
{147}{}{Vid� poni�en� dve�e se z�mkem.}
{148}{}{Vid� poni�en� dve�e bez zjevn�ho odemykac�ho za��zen�.}
{149}{}{Vid� poni�en� dve�e se star�m, rezav�m z�mkem.}

# Perception Check Failure

{150}{}{Vid� star� dve�e se z�mkem, kter� m��e� odemknout pomoc� pakl���, a vysoce v�bu�nou past� um�st�nou na z�rubni dve��.}
{151}{}{Vid� star� dve�e se z�mkem a vysoce v�bu�nou past� um�st�nou na z�rubni dve��.}
{152}{}{Vid� star� dve�e bez zjevn�ho odemykac�ho za��zen� a vysoce v�bu�nou past� um�st�nou na z�rubni dve��.}
{153}{}{Vid� star� dve�e se star�m, rezav�m z�mkem a vysoce v�bu�nou past� um�st�nou na z�rubni dve��.}

{154}{}{Vid� star� dve�e se z�mkem, kter� m��e� odemknout pomoc� pakl���, a past� um�st�nou na z�rubni dve��.}
{155}{}{Vid� star� dve�e se z�mkem a past� um�st�nou na z�rubni dve��.}
{156}{}{Vid� star� dve�e bez zjevn�ho odemykac�ho za��zen� a past� um�st�nou na z�rubni dve��.}
{157}{}{Vid� star� dve�e se star�m, rezav�m z�mkem a past� um�st�nou na z�rubni dve��.}

{158}{}{Vid� star� dve�e se z�mkem, kter� m��e� odemknout pomoc� pakl���, a kousek dr�tku, jen� �ouh� ze z�rubn� dve��.}
{159}{}{Vid� star� dve�e se z�mkem a kousek dr�tku, jen� �ouh� ze z�rubn� dve��.}
{160}{}{Vid� star� dve�e bez zjevn�ho odemykac�ho za��zen� a kousek dr�tku, jen� �ouh� ze z�rubn� dve��.}
{161}{}{Vid� star� dve�e se star�m, rezav�m z�mkem a kousek dr�tku, jen� �ouh� ze z�rubn� dve��.}

{162}{}{Vid� star� dve�e se z�mkem, kter� m��e� odemknout pomoc� pakl���.}
{163}{}{Vid� star� dve�e se z�mkem.}
{164}{}{Vid� star� dve�e bez zjevn�ho odemykac�ho za��zen�.}
{165}{}{Vid� star� dve�e se star�m, rezav�m z�mkem.}

#############################################################
#  The following lines are for damage done to the player or #
#  critter who tried to open the door, or failed a traps    #
#  roll.                                                    #
#############################################################

# The following sets of lines are to be translated as:
# You set off the trap and were hit for [x] points of damage.
# NPC sets of the trap and was hit for [x] points of damage.

# Player sets off the trap
{166}{}{Zne�kodnil jsi past a byl jsi zasa�en za }
{167}{}{ bod� po�kozen�.}

# NPC sets off the trap
{168}{}{ zne�kodnil past a byl zasa�en za }
{169}{}{ bod� po�kozen�.}

#############################################################
#  The following lines are for when the player uses skills  #
#  on the door.                                             #
#############################################################

# Player uses a skill on the door
# Unlock Door
{170}{}{�sp�n� odemyk� z�mek na dve��ch.}
{171}{}{D�ky sv� ne�ikovnosti se z�mek dve�� zasekl.}
{172}{}{Dve�e se ti nepovedlo odemknout.}

# Lock Door
{189}{}{�sp�n� si zamkl dve�e.}
{190}{}{Dve�e se ti nepovedlo zamknout.}

# Find Trap on the Door
{194}{}{Na�el jsi na dve��ch past.}
{195}{}{Nepovedlo se ti naj�t past na t�chto dve��ch.}

# Disarm the Trap on the Door
{196}{}{Zku�en� zne�kod�uje� past na dve��ch.}
{198}{}{Nepovedlo se ti zne�kodnit past na dve��ch.}

# NPC uses a skill on the door
# The following lines are appended with the NPC's name

# Unlock Door
{173}{}{ �sp�n� odemkl z�mek dve��.}
{174}{}{ nezku�enost zp�sobila zaseknut� z�mku dve��.}
{175}{}{ se nepovedlo dve�e zamknout.}

# Lock Door
{191}{}{ �sp�n� zamkl dve�e.}
{192}{}{ se nepovedlo dve�e zamknout.}

# Find Trap on the Door
{199}{}{ na�el na dve��ch past.}
{200}{}{ se nepovedlo naj�t na dve��ch past.}

# Disarm the Trap on the Door
{201}{}{ zku�en� zne�kodnil past na dve��ch.}
{202}{}{ se nepovedlo zne�kodnit past na dve��ch.}

# Using a key on the door.
{400}{}{Odemkl jsi dve�e.}

#############################################################
#  The following lines are for when the player tries to     #
#  use items on the door which are not lockpicks.           #
#############################################################

# Player uses an item on the door
{176}{}{Vyp��il jsi z�mek u dve��.}
{177}{}{Kdy� ses pokou�el vyp��it z�mek, poranil sis z�da, a to ti zp�sobilo jeden bod po�kozen�.}

# The following set of lines is to be translated as:
# While trying to bust the lock, you strain your back and
# take [x] points of damage.

{178}{}{Kdy� ses pokou�el vyp��it z�mek, poranil sis z�da, co� ti zp�sobilo po�kozen� za }
{179}{}{ bod�.}
{180}{}{Na to, abys vyp��il tento z�mek, jsi p��li� slab�.}

# NPC uses an item on the door
# The following lines are prepended by the NPC's name
{181}{}{ vyp��il z�mek u dve��.}
{182}{}{ si poranil z�da, kdy� se pokou�el vyp��it z�mek, co� mu zp�sobilo jeden bod po�kozen�.}

# The following line set of lines is to be translated as:
# NPC strains his back while trying to bust the lock and
# takes [x] points of damage

{183}{}{ si poranil z�da, kdy� se pokou�el vyp��it z�mek, co� mu zp�sobilo po�kozen� za }
{184}{}{ bod�.}

{185}{}{ je na vyp��en� z�mku p��li� slab�.}
{186}{}{ si poranila z�da, kdy� se pokou�ela vyp��it tento z�mek, co� j� zp�sobilo jeden bod po�kozen�.}

# The following line set of lines is to be translated as:
# NPC strains her back while trying to bust the lock and
# takes [x] points of damage

{187}{}{ si poranila z�da, kdy� se pokou�ela vyp��it tento z�mek, zp�sobilo po�kozen� za }
{188}{}{ bod�.}

#############################################################
#  Damage done to the door due to explosives.               #
#############################################################

{193}{}{V�buch na t�ch dve��ch neud�lal ani �kr�banec.}

#############################################################
#  Reporting Door Status should it be used.                 #
#############################################################

{203}{}{Dve�e se zdaj� b�t zam�en�. Vypad� to, �e tyhle jako kl�� vy�aduj� n�jakou tenkou kartu.}
{204}{}{Sly�� tich� prask�n� elektrick�ch v�boj� prob�haj�c�ch dve�mi.}

# NPC finds trap
# The following line is to be translated as:
# NPC notices a trap in the door jamb.

{205}{}{ oznamuje, �e sly�� tich� prask�n� elektrick�ch v�boj� prob�haj�c�ch dve�mi.}

#############################################################
#  Setting traps on a door and whether the door is open or  #
#  closed to set the trap.                                  #
#############################################################

# Player tries to set a trap on an open door
{206}{}{Na ty dve�e nejsi schopen um�stit past, proto�e jsou otev�en�.}

# NPC tries to set a trap on an open door
{207}{}{ nen� schopen na ty dve�e um�stit past, proto�e jsou otev�en�.}

# Player tries to set a trap on a closed door
{208}{}{Zku�en� jsi na r�m dve�� um�stil past.}
{209}{}{Nepovedlo se ti um�stit past na r�m dve��.}

# NPC tries to set a trap on a closed door
{210}{}{ zku�en� um�stil past na r�m dve��.}
{211}{}{ nedok�zal um�stit past r�m dve��.}

{300}{}{Odemkl jsi dve�e.}
{301}{}{Zamkl jsi dve�e.}
{302}{}{Dokud jsou ty dve�e otev�en� nem��e� je zamknout.}
{303}{}{Tenhle kl�� do toho z�mku nepasuje.}

# for broken doors
{320}{}{Neexistuje ��dn� zp�sob, jak zamknout tyhle dve�e.}

{500}{}{Neexistuje ��dn� zp�sob, jak zne�kodnit past na t�chto dve��ch.}
