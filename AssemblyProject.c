#include <string.h>
#include <stdlib.h>
#include <stdio.h>

				 //0	1	 2	  3	   4	5	 6	  7	   8	9	 10	  11
char place[12] = {'S', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'Z' };
int forward[12] = {2, -1, 6, 9, 11, 10, 3, 4, 9, 5, 7};
int left[12] = {-1, 6, 1, 8, 8, -1,9 ,-1 ,11 ,10 ,-1};
int right[12] = {-1, 7, 2, 11, 2, -1, 4, 5, -1, 6, 9};	
	
main (){

	//Variables:
	int random;
	//Perk Variables
	int strength = 50;
	int agility = 50;
	int intel = 50;
	//Name Array
	char name[20];
	//Gender Choice
	int gender; 
	//Starting Health
	int health = 100; 
	//Starting location
	int location = 0;
	//Start Character at Start
	char at = place[location]; 
	
	//Begin Character Creation	
	//Character Name --> Prompt for user input, save input as character name
	printf("%s\n", "Welcome to Superhero Sojourn!\nPlease provide a character name ");
	scanf("%s", name);

	//Character Gender --> Prompt for user input, save input as character gender
	printf("%s\n", "Pick a gender(simply cosmetic): 1. Male 2. Female ");
	while(gender != 1 && gender != 2){
		scanf("%d", &gender);
	}

	//Character Main Perk --> Prompt for user input, save input as character main perk
	printf("%s\n", "What means more to you? 1. Agility 2. Strength 3. Intelligence");
	int perkOne;
	while(perkOne != 1 && perkOne != 2 && perkOne != 3){
		scanf("%d", &perkOne);
	}

	//Randomize the bonus character gets to character main perk
	if(perkOne == 1){
		srand(time(NULL));
		agility += ( rand() % 50 ) + 1;  	 				
	} else if (perkOne == 2){
		srand(time(NULL));
		strength += ( rand() % 50 ) + 1;	
	} else if (perkOne == 3){
		srand(time(NULL));
		intel += ( rand() % 50 ) + 1;	
	}
	
//Loop for entire game. Runs as long as you haven't reached the last location or you haven't hit Game Over!
while( location <= 11){
			
		//Swtich identifies which locaiton user is at and performs proper code for that location.
		switch(location){
			
			//Location S - Start
			case 0:
					printf("%s\n", "Your adventure begins!\n. . .");
					printStatus(strength, agility, intel, health);
					break; 
			//Location A - Xavier School (nothing)
			case 1:
					printf("%s\n", "You see what looks like a mansion in the distance and approach the large gate.\n. . .");
					printf("%s\n", "Upon a closer look, you recognize the mansion at Professor Xavier's School for Gifted Youngsters!\n");
					random = rand() % 51;
					if(random > 25){
						health = health + 5;
						printf("%s\n", "You are greeted by Professor Xavier himself! He lets you rest up and sends you off with some words of wisdom.\n. . .");
					}else{
						health = health - 10;
						printf("%s\n", "You are greeted by an odd Professor Xavier... You quickly find out that this is actually Mystique in disguise! You lose 10 HP because of the fight that ensues.\n. . ."); 
					}
					printStatus(strength, agility, intel, health);				
					break;
			//Location B - Pallet Town (nothing)
			case 2:
					printf("%s\n", "You are in Pallet Town. POKEMON BATTLE\n. . .");
					if(intel > 50){
						intel--;; 
						health = health - 5;
						printf("%s\n", "Your high intelligence is perfect for this situation! Your extensive knowledge of Pokemon battling is most helpful. You only lose 5 HP!\n. . .");
					}else{
						intel = intel - 5;
						health = health - 15;
						printf("%s\n", "Too bad, you don't have a higher intelligence! Your Pokemon needed a smart trainer. You lose 15 HP!\n. . ."); 
					}
					
					if(health > 0){
							printf("%s\n", "You manage to win the battle!\n. . .");	
					}else{
							printf("%s\n", "You lost the battle and pass out.\n GAME OVER.\n. . .");
							location = 100;
					}
					printStatus(strength, agility, intel, health);				
					break;
			//Location C - Starbucks (rest --> +5 health)
			case 3:
					printf("%s\n", "STARBUCKS RUN! +5 health to you!\n. . .");
					health = health + 5; 
					printStatus(strength, agility, intel, health);			
					break;
			//Location D - Knights-Knee (intel battle)
			case 4:
					printf("%s\n", "You have encountered the Knights who say Kneee, Knee, Knee! They begin to approach you menacingly!\n. . .");
					
					if(intel > 50){
						intel--;; 
						health = health - 5;
						printf("%s\n", "Your high intelligence is perfect for this situation! Your extensive knowledge of the Knights aids in your interaction with them. You only lose 5 HP!\n. . .");
					}else{
						intel = intel - 5;
						health = health - 15;
						printf("%s\n", "Too bad, you don't have a higher intelligence! Strength and agility don't help against these Knights. 'You lose 15 HP!\n. . ."); 
					}
					
					if(health > 0){
							printf("%s\n", "You were able to produce a shrubbery!\n. . .");	
					}else{
							printf("%s\n", "You are forced to face the Dark Knight and recieve a few flesh wounds.\n GAME OVER.\n. . .");
							location = 100;
					}
					printStatus(strength, agility, intel, health);				
					break;
			//Location E - Zombies (agility battle)
			case 5:
					printf("%s\n", "ZOMBIE ATTACK!\n. . .");
					
					if(agility > 50){
						agility--;
						health = health - 5;
	 					printf("%s\n", "Your high agility is perfect for this situation! Your speed and dexterity help you evade the Zombies with ease! You only lose 5 HP!\n. . .");
					}else{
						agility = agility - 5; 
						health = health - 15;
	 					printf("%s\n", "Too bad, you don't have a higher agility! Quickness is essential when dealing with Zombies. You lose 15 HP!\n. . ."); 
					}	
					
					if(health > 0){
							printf("%s\n", "You successfully evade the Zombies and find the cure.\n. . .");	
					}else{
							printf("%s\n", "A zombie bites you and you turn into a zombie superhero. BRAINS!\n GAME OVER.\n. . .");
							location = 100;
					}
					printStatus(strength, agility, intel, health);			
					break;
			//Location F - Park (nothing)
			case 6:
					printf("%s\n", "You take a lovely stroll through Central Park!\n. . .");
					printStatus(strength, agility, intel, health);				
					break;
			//Location G - Dr.Doom (strength battle)
			case 7:
					printf("%s\n", "You have reached a nice castle, but the crazy scientist Dr. Doom ambushes you!\n. . .");
					
					if(strength > 50){
						strength--;
						health = health - 5;  					
						printf("%s\n", "Your high strength is perfect for this situation! Your incredible might allows you to put up a fair fight. You only lose 5 HP!\n. . .");
					}else{
						strength = strength - 5; 
						health = health - 20;  					
						printf("%s\n", "Too bad, you don't have a higher strength! You could have taken less damage. You lose 20 HP!\n. . .");
					}
					if(health > 0){
							printf("%s\n", "IT'S CLOBBERING TIME! You were able to defeat the Dr. Doom!\n. . .");	
					}else{
							printf("%s\n", "Too bad for you, this isn't Fantastic Four, but merely the Fantastic One. You die.\n GAME OVER.\n. . .");	
							location = 100;
					}
				printStatus(strength, agility, intel, health);			
				break;
			//Location H - Khaleesi (rest --> +5 to all perks)
			case 8:
					printf("%s\n", "Khaleesi, Mother of Dragons, appears! You feel more powerful! (+5 to all perks!)\n. . ."); 
					strength = strength + 5;
					intel = intel + 5;
					agility = agility + 5;
					printStatus(strength, agility, intel, health);				
					break;
			//Location I - HauntedVillage (battle w/o perk)
			case 9:
					printf("%s\n", "You are in a haunted village. You are hunting Diablo to aid local villagers.\n. . . ");
					
					if(agility > 50){
						agility--;
						health = health - 5;  					
						printf("%s\n", "Your high agility is perfect for this situation! Your incredible speed and dexterity make you a perfect hunter! You only lose 5 HP!\n. . .");
					}else{
						agility = agility - 5; 
						health = health - 20;  					
						printf("%s\n", "Too bad, you don't have a higher agility! A strong or intelligent hero don't make for as good a hunter as an agile one. You lose 20 HP!\n. . .");
					}					
					if(health > 0){
							printf("%s\n", "You smite the demon, sending him back to H-E-Double-Hockey-Sticks.\n. . .");	
					}else{
							printf("%s\n", "You lose and spend enternity burning, yeesh!\n GAME OVER.\n. . .");
							location = 100;
					}
					printStatus(strength, agility, intel, health);
					break;
			//Location J - RadioStation (nothing)
			case 10:
				    printf("%s\n", "You are at a radio station! You say hi to mommy dearest!\n. . .");
					printStatus(strength, agility, intel, health);
					break;
			//Location Z - FINISH (boss battle)
			case 11:
					printf("%s\n", "You have reached the end of the maze! Your archnemesis appears! It's' Herve! the big boss, the untouchable, the almighty!!\n. . .");
					
					if(health > 25){
							printf("%s\n", "You defeated Herve, and took no damage!\n YOU WIN!!!");	
							location = 100;
					}else{
							printf("%s\n", "You were unable to defeat Herve and died in a horrible way. You were so close too!\n GAME OVER.\n. . .");
							health = health - health; 
							printStatus(strength, agility, intel, health);
							location = 100;
					}	
					printStatus(strength, agility, intel, health);
					break;
			default:break; 
		} 
		
		//Following code handles movement and checking for dead-ends
		//Reach end of location array? --> Yes = Finished, No = Continue
		if(location <= 11){
			printf("%s\n", "\n\n1. Forward\n2. Left\n3. Right.");
			int move; 
			scanf("%d", &move);
			//Switch moves user through maze, checks for forward, left, or right (according to user input of 1, 2, or 3)
			switch (move){
				//NOTE: -1 are considered dead-ends, but there are only three unique dead-ends. It is possible to encounter one more than the other.
				//Dead-ends are not considered as locations and as such are not part of the place array.
				case 1: 		
								if(forward[location] == -1){
									printf("%s\n", "\nBad luck, you fell into a interdimensional portal and are lost in the space time continuum.\n. . .");
									location = 100;
									break;
								}
								location = forward[location];
								at = place[location];
								break;
				case 2: 
								if(left[location] == -1){
									printf("%s\n", "\nSuprise! Top throws a never-ending exam your way!\n. . .");
									location = 100;
									break;
								}
								location = left[location];
							 	at = place[location];
							 	break;
				case 3: 
								if(right[location] == -1){
									printf("%s\n", "\nYou slip and fall into well. Too bad, Lassie isn't around to get help.\n. . .");
									location = 100;
									break;
								}
								location = right[location];
							  	at = place[location];
							 	break; 
				default: 
						printf("%s\n", "\nINVALID MOVE!\n");
						break;	
			}
		}
	}
	
	printf("%s\n", "\nGAME OVER!\n");
}

//Function used to print character's current stats.
printStatus(int strength, int agility, int intel, int health){
	printf("\nStrength =  %d", strength);
	printf("\nAgility = %d", agility);
	printf("\nIntelligence =  %d", intel);
	//printf("\nWeapon Strength = %d", weaponStrength);
	//printf("\nHit Percent = %d", hitChance);
	printf("\nHEALTH = %d", health);
	printf("%s\n", "\n-----------------------------------------------------------------");	
}


