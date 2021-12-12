#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;

string modifiers[21] = {"Damp", "Thriller", "Fierce", "Bellowing", "Crumbling", 
"Mystery", "Hot", "Suffocation", "Rusty", "Secret", "Slippery", "Echoing", 
"Smelly", "Concrete", "Greedy", "Last", "First", "Red", "Green", "Yellow", "Corroded"};

string places[7] = {"Room", "Castle", "Garden", "Pit", "Den", "Canyon", "Trial"};

string easyEnemies[128] = {"Kochappy","Tank","Wtank","Catfish","Tadpole","Mar","Egg", "LeafChappy", "ShijimiChou"};
string hardEnemies[128] = {"Chappy", "Hiba","GasHiba","ElecHiba","Frog","Bomb","Kabuto"};

string treasures[256] = {"ahiru", "apple", "apple_blue", "bane", "baum_kuchen", "be_dama_red", "be_dama_yellow", "be_dama_blue", "bell", "bey_goma", "bird_hane", "bolt", "channel", "chess_king_black", "chess_king_white", "chess_queen_black", "chess_queen_white", "chocolate", "chocoichigo", "chocowhite", "compact", "cookie", "creap", "diamond_red", "diamond_blue", "diamond_green","doll","donguri","donutschoco","donutsichigo","donutswhite","flower_red","flower_blue","toy_gently","toy_lady","toy_dog","toy_cat","gear","gold_medal","gum_tape","halloween","haniwa","ichigo","juji_key","kan","kinoko","kouseki_suisyou","kumakibori","locket","makigai","matu_bokkuri","milk_cap","momiji_normal","momiji_kare","momiji_red","nut","tatebue","saru_head","sensya","sinkukan","silver_medal","tel_dial","toy_ring_a_red","toy_ring_a_blue","toy_ring_a_green","toy_ring_b_red","toy_ring_b_blue","toy_ring_b_green","toy_ring_c_red","toy_ring_c_red","toy_ring_c_green","toy_ring_c_blue","toy_teala","turi_uki","watch","Xmas_item","yoyo_red","yoyo_yellow","yoyo_blue","flask","elec","fire","gas","water","mojiban"};

string unitFiles[256] = {"1_ABE_ari_metal.txt", "1_ABE_king_tsuchi.txt", "1_ABE_manp_boss_conc.txt", "1_ABE_mid1_boss_tsuchi.txt", "1_ABE_mid1_metal.txt", "1_ABE_mid1_tsuchi.txt", "1_ABE_vshit67_toy.txt", "1_MAT_cent2_tsuchi.txt", "1_MAT_danh_conc.txt", "1_MAT_h446_metal.txt", "1_MAT_hit224_cap_icap_metal.txt"};

//planned for later: randomly generate a theme and then generate skybox/lighting/units(even enemies?) from that.

string themes[7] = {"Concrete", "Garden", "Metal", "Snow", "Soil", "Toybox", "Tiles"};


int getSeed();
string getName();


int writeCaveInfo();
int writeFloorInfo();
int writeTekiInfo();
int writeItemInfo();
int writeGateInfo();
int writeCapInfo();

int SaveFile();

#endif
