/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#pragma once
#include <SDL.h>
#include <stdio.h>
#include "LineDrawing.h"
//#include "DrawWrapper.h"
#include "Vec3.h"
#include <float.h>
#include "3DRenderer.h"

float RandomFloat(float a, float b) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
	
//The surface contained by the window
//SDL_Surface* gScreenSurface = NULL;

SDL_Renderer* gRenderer = NULL;

Renderer renderer;

/////////MARIO
std::vector<double> mario = {-19.802860260010, 20.389814376831, -33.870559692383,
-21.111415863037, 28.260528564453, 3.146151781082	,
-8.386551856995, 19.149011611938, -26.392362594604	,
-34.396423339844, 18.908136367798, -26.280166625977	,
-38.806732177734, 19.751369476318, 6.518849372864	,
-19.996280670166, 19.029388427734, 22.412893295288	,
-4.009655475616, 16.944013595581, 6.839295864105	,
-27.368278503418, -0.069835692644, -36.094444274902	,
-13.795372962952, 0.033755600452, -34.871425628662	,
-4.470590591431, 0.008795529604, -23.632944107056	,
-38.489803314209, 0.022664576769, -23.210077285767	,
-31.760223388672, -0.013260126114, 28.201856613159	,
-41.420982360840, 0.042685016990, 14.424512863159	,
-9.358499526978, 0.096507236362, 28.378351211548	,
-1.004970192909, 0.023515939713, 14.160419464111	,
-20.283405303955, 42.784378051758, 4.497829914093	,
-20.633113861084, 18.998819351196, 6.656611442566	,
-2.637970447540, 18.933618545532, -7.523067474365	,
-10.827259063721, 42.916938781738, -27.853736877441	,
-9.693902969360, 19.004163742065, -29.757047653198	,
-30.438755035400, 42.645805358887, -28.079137802124	,
-31.692661285400, 18.669578552246, -29.513196945190	,
-38.646137237549, 18.795967102051, -7.243574142456	,
-4.643190860748, 42.980945587158, -7.991017341614	,
-20.537517547607, 50.701850891113, -13.451384544373	,
-36.665668487549, 42.932128906250, -8.227418899536	,
-20.310607910156, 12.228815078735, -13.413058280945	,
-20.249179840088, 73.940071105957, 9.266019821167	,
-20.286415100098, 42.967952728271, 4.494485855103	,
-0.705040216446, 74.060943603516, -6.559635162354	,
-10.843237876892, 42.943489074707, -28.314462661743	,
-8.255529403687, 73.984481811523, -32.060825347900	,
-32.658794403076, 73.948158264160, -31.781311035156	,
-30.049594879150, 42.992103576660, -28.187469482422	,
-40.323043823242, 73.704277038574, -6.630165100098	,
-36.091114044189, 81.268096923828, -8.251564025879	,
-20.519210815430, 81.933753967285, 4.514862060547	,
-20.327022552490, 86.699501037598, -13.612789154053	,
-30.274803161621, 81.561035156250, -28.131193161011	,
-10.657206535339, 81.554367065430, -27.871179580688	,
-36.254669189453, 42.730926513672, -7.898213386536	,
-20.260490417480, 34.112850189209, -13.171175003052	,
-4.643252849579, 42.920822143555, -7.989800453186	,
-4.868465900421, 81.488441467285, -7.934606552124	,
-0.199854552746, 0.325402736664, 14.345031738281	,
30.368022918701, 0.192061901093, 28.276779174805	,
8.368103981018, 0.277999281883, 28.668931961060		,
40.609653472900, 0.211477801204, 14.488171577454	,
2.967858552933, 0.051737979054, -23.282859802246	,
36.972602844238, -0.013330236077, -23.438344955444	,
12.437949180603, -0.249452769756, -35.047180175781	,
26.026840209961, -0.170844301581, -36.093013763428	,
37.463569641113, 19.627964019775, 6.727581977844	,
2.695775747299, 16.779161453247, 6.681618690491		,
7.085346221924, 19.042825698853, -26.208106994629	,
33.091587066650, 18.872360229492, -26.269460678101	,
18.851909637451, 19.187328338623, 22.628587722778	,
18.579471588135, 20.300863265991, -34.027847290039	,
20.110717773438, 27.984088897705, 3.249917030334	,
37.237213134766, 18.890312194824, -7.067957878113	,
19.356739044189, 42.892002105713, 4.404170513153	,
19.142642974854, 18.743629455566, 6.813200950623	,
30.587562561035, 18.853897094727, -29.544248580933	,
29.172660827637, 42.816825866699, -27.968393325806	,
8.585720062256, 18.634248733521, -29.711242675781	,
1.237073659897, 18.783714294434, -7.329830169678	,
9.570795059204, 42.575691223145, -28.119947433472	,
3.438262939453, 42.835739135742, -8.126464843750	,
35.436401367188, 42.575317382813, -7.912250518799	,
19.139598846436, 50.975097656250, -13.218795776367	,
19.229343414307, 12.921718597412, -13.098208427429	,
3.353694438934, 81.253036499023, -8.048166275024	,
19.274181365967, 81.707763671875, 4.452166080475	,
19.036201477051, 86.693107604980, -13.601773262024	,
9.488056182861, 81.212463378906, -28.069292068481	,
28.689926147461, 81.455192565918, -27.973356246948	,
34.957031250000, 81.363723754883, -8.266258239746	,
28.775970458984, 42.922649383545, -28.114034652710	,
35.041515350342, 42.863029479980, -8.010066032410	,
19.005168914795, 34.143989562988, -13.431281089783	,
9.574102401733, 42.680778503418, -28.211227416992	,
3.439745426178, 42.721824645996, -8.190105438232	,
18.955047607422, 42.812297821045, 4.737411022186	,
7.051390171051, 73.705276489258, -31.900394439697	,
-0.716541886330, 73.773811340332, -6.674171447754	,
31.453224182129, 73.906028747559, -31.768615722656	,
39.283573150635, 73.847503662109, -6.437049865723	,
19.181365966797, 74.052513122559, 9.073377609253	,
-69.307693481445, 91.452606201172, -4.111574172974	,
-87.475219726563, 96.485267639160, -19.559768676758	,
-75.458976745605, 86.038238525391, 1.274721980095	,
-72.884262084961, 93.967208862305, -38.821647644043	,
-79.406829833984, 89.986381530762, -43.706153869629	,
-77.023300170898, 104.827857971191, -20.267410278320,
-65.988182067871, 95.581901550293, 1.127644777298	,
-70.426208496094, 98.981819152832, -43.536991119385	,
-55.965435028076, 86.707092285156, -37.315734863281	,
-59.233921051025, 82.438430786133, -12.246812820435	,
-53.366176605225, 84.466552734375, -9.744806289673	,
-59.852210998535, 100.117126464844, -22.060712814331,
-93.068374633789, 74.019332885742, -43.995201110840	,
-88.653617858887, 69.758674621582, 2.187176942825	,
-62.246128082275, 60.074050903320, -3.033412933350	,
-64.026992797852, 61.540222167969, -21.534997940063	,
-74.933395385742, 56.222648620605, -8.143049240112	,
-101.873611450195, 79.694908142090, -19.375936508179,
-89.825431823730, 59.997619628906, -23.731073379517	,
-75.794860839844, 57.108955383301, -18.098939895630	,
-75.818626403809, 64.973243713379, -36.955131530762	,
-73.657196044922, 73.980491638184, -43.314815521240	,
-61.372051239014, 74.294647216797, -23.649810791016	,
-61.041450500488, 84.435836791992, -33.928588867188	,
-77.338424682617, 98.772468566895, -20.121765136719	,
-55.759761810303, 119.629188537598, -15.404123306274,
-68.522613525391, 104.709281921387, -16.496318817139,
-46.789951324463, 110.646774291992, -7.299620628357	,
-60.743476867676, 96.988777160645, -9.381776809692	,
-38.529769897461, 102.409301757813, -17.221593856812,
-53.563827514648, 89.775390625000, -18.313922882080	,
-42.414947509766, 106.645202636719, -31.021057128906,
-57.036785125732, 93.444915771484, -29.784864425659	,
-52.871208190918, 117.100265502930, -29.990663528442,
-66.086524963379, 102.499794006348, -29.000307083130,
-43.914150238037, 114.270248413086, -11.459427833557,
-49.610191345215, 120.352661132813, -16.867382049561,
-47.887138366699, 118.696945190430, -26.845781326294,
-40.808166503906, 111.603271484375, -27.284515380859,
-38.030307769775, 108.780166625977, -18.094932556152,
-64.760604858398, 94.384582519531, -20.771242141724	,
-43.214214324951, 134.844253540039, -7.487434387207	,
-55.038051605225, 119.734848022461, -15.132543563843,
-34.916118621826, 121.558555603027, 1.749679803848	,
-48.670295715332, 108.800224304199, -7.553240776062	,
-22.642837524414, 113.611976623535, -9.640822410583	,
-38.623741149902, 102.831787109375, -16.920385360718,
-23.524841308594, 122.394729614258, -25.609970092773,
-39.573276519775, 109.763206481934, -29.255897521973,
-36.061786651611, 135.250122070313, -24.138975143433,
-49.576862335205, 120.099433898926, -28.227235794067,
-29.745708465576, 126.911331176758, -2.384677886963	,
-34.521133422852, 135.113525390625, -8.070141792297	,
-30.408950805664, 135.285217285156, -18.029739379883,
-22.874591827393, 127.597023010254, -18.987222671509,
-22.046718597412, 122.128494262695, -9.166134834290	,
-55.150276184082, 114.925338745117, -17.671068191528,
-43.740165710449, 103.190353393555, -18.944765090942,
-51.169002532959, 115.374038696289, -26.700508117676,
-44.197273254395, 108.245803833008, -27.559423446655,
-50.535350799561, 107.796836853027, -12.500144958496,
66.958793640137, 89.138206481934, -1.468152284622	,
85.439323425293, 97.309997558594, -15.220306396484	,
75.544242858887, 98.166786193848, -16.933439254761	,
62.779563903809, 72.299186706543, -21.991907119751	,
58.644939422607, 79.720420837402, -10.922614097595	,
61.574329376221, 82.589347839355, -32.014480590820	,
72.072349548340, 93.696105957031, -35.727321624756	,
73.936241149902, 104.270645141602, -16.536960601807	,
56.535785675049, 83.979156494141, -35.552433013916	,
52.343624114990, 80.770912170410, -8.272511482239	,
95.310333251953, 76.458206176758, -40.465171813965	,
101.873626708984, 82.659202575684, -15.127761840820	,
88.434379577637, 69.659049987793, 5.462704181671	,
77.206489562988, 55.243015289307, -6.281580448151	,
66.685058593750, 59.975822448730, -20.191238403320	,
78.543670654297, 56.366203308105, -16.159648895264	,
92.440330505371, 61.560932159424, -20.797060012817	,
78.848884582520, 65.161781311035, -34.619068145752	,
76.117111206055, 73.795036315918, -41.037075042725	,
80.070701599121, 90.572784423828, -40.342987060547	,
64.004051208496, 57.498851776123, -1.741734266281	,
73.448204040527, 84.397338867188, 4.249444961548	,
63.057147979736, 92.917587280273, 3.630530834198	,
57.457374572754, 97.713829040527, -19.612945556641	,
69.509506225586, 98.598533630371, -40.504966735840	,
56.785137176514, 94.427520751953, -30.186798095703	,
54.434177398682, 118.355621337891, -28.346977233887	,
65.963142395020, 102.473457336426, -26.251722335815	,
54.188591003418, 119.129402160645, -13.419340133667	,
65.828002929688, 103.280189514160, -13.360262870789	,
43.739299774170, 110.264656066895, -8.245042800903	,
56.607540130615, 95.970687866211, -9.350481987000	,
36.919944763184, 104.000579833984, -20.507297515869	,
50.894290924072, 90.191276550293, -19.659809112549	,
43.797222137451, 109.035728454590, -32.776641845703	,
48.903095245361, 119.995925903320, -25.950584411621	,
41.766933441162, 113.734451293945, -29.195053100586	,
36.944187164307, 110.354904174805, -20.794050216675	,
41.490962982178, 114.532630920410, -12.619105339050	,
48.748622894287, 120.696884155273, -15.968828201294	,
62.474132537842, 93.849960327148, -19.593194961548	,
40.525394439697, 112.262313842773, -31.437431335449	,
38.181911468506, 137.212188720703, -22.532176971436	,
51.053245544434, 121.277572631836, -27.517841339111	,
42.363521575928, 133.391693115234, -5.592382907867	,
54.474094390869, 118.276138305664, -13.681602478027	,
31.869380950928, 119.896972656250, 0.331676483154	,
45.910713195801, 107.397926330566, -8.883060455322	,
20.701057434082, 115.016929626465, -13.992826461792	,
37.210670471191, 103.561012268066, -20.236509323120	,
24.713966369629, 125.811981201172, -27.802566528320	,
31.418205261230, 136.728179931641, -17.494928359985	,
23.516761779785, 130.007644653320, -20.525545120239	,
21.173564910889, 123.140274047852, -12.068477630615	,
27.698364257813, 126.187179565430, -3.586055278778	,
34.351654052734, 134.285934448242, -6.897671699524	,
44.614089965820, 109.873725891113, -29.254600524902	,
42.497283935547, 103.759918212891, -21.790386199951	,
51.932598114014, 116.082786560059, -26.422554016113	,
54.234577178955, 114.142951965332, -16.877996444702	,
48.415328979492, 106.463066101074, -13.868508338928	,
-11.011650085449, 83.797492980957, 22.905975341797	,
-14.224571228027, 71.459571838379, 19.112113952637	,
12.973817825317, 71.431114196777, 19.112112045288	,
-37.400218963623, 93.202819824219, -13.749755859375	,
-0.591428101063, 104.630226135254, -5.168066501617	,
-14.996886253357, 97.899757385254, -34.077636718750	,
35.794204711914, 92.410430908203, 6.241432666779	,
37.379165649414, 78.056030273438, 3.215636253357	,
36.194942474365, 93.119148254395, -13.349442481995	,
-32.204914093018, 90.256927490234, -30.197128295898	,
-40.215305328369, 78.795547485352, -13.176446914673	,
-19.008937835693, 86.388534545898, -39.459369659424	,
13.801500320435, 97.869598388672, -34.077636718750	,
30.991878509521, 90.197654724121, -30.597057342529	,
17.389442443848, 86.350425720215, -39.459369659424	,
14.964400291443, 62.437660217285, 5.768721103668	,
28.173976898193, 73.102081298828, 13.538030624390	,
24.587295532227, 85.822357177734, 18.938817977905	,
14.599383354187, 95.844306945801, 18.297012329102	,
9.786743164063, 83.775695800781, 22.905973434448	,
-16.199001312256, 95.876548767090, 18.297016143799	,
-37.000961303711, 92.486640930176, 6.241438388824	,
-25.809482574463, 85.875152587891, 18.938821792603	,
-16.233985900879, 62.470333099365, 5.768724441528	,
-29.422798156738, 73.162391662598, 13.538036346436	,
-32.227642059326, 68.536506652832, 2.663291692734	,
16.165416717529, 63.410694122314, -30.619159698486	,
-0.627307653427, 70.370658874512, -39.710708618164	,
21.373142242432, 72.315811157227, -37.679374694824	,
-35.016727447510, 77.442909240723, -29.199047088623	,
-22.623638153076, 72.361869812012, -37.679370880127	,
33.778461456299, 77.376693725586, -29.597898483276	,
-38.616416931152, 77.735504150391, 3.208821773529	,
-17.432971954346, 63.445877075195, -30.619155883789	,
30.968708038330, 68.070526123047, 2.656705617905	,
38.979862213135, 78.712615966797, -13.176452636719	,
31.768131256104, 67.515853881836, -12.952356338501	,
-33.028636932373, 67.590560913086, -13.352458953857	,
13.426414489746, 121.657325744629, 20.291635513306	,
15.810528755188, 106.486938476563, 25.978021621704	,
24.206382751465, 104.051246643066, 21.191915512085	,
11.418481826782, 114.083091735840, 24.334486007690	,
29.812221527100, 109.619422912598, 16.760494232178	,
29.018501281738, 115.612159729004, 15.126261711121	,
23.025207519531, 122.022155761719, 15.888828277588	,
-14.171974182129, 121.686225891113, 20.291639328003	,
-16.587856292725, 106.520866394043, 25.978025436401	,
-12.179910659790, 114.107803344727, 24.334489822388	,
-24.990398406982, 104.102752685547, 21.191919326782	,
-29.778289794922, 115.673728942871, 15.126267433167	,
-23.771579742432, 122.071159362793, 15.888832092285	,
-30.584560394287, 109.682670593262, 16.760498046875	,
13.426414489746, 121.657333374023, 20.291635513306	,
-14.171975135803, 121.686225891113, 20.291639328003	,
11.418481826782, 114.083091735840, 24.334486007690	,
-12.179910659790, 114.107803344727, 24.334489822388	,
-16.587856292725, 106.520858764648, 25.978025436401	,
15.810528755188, 106.486938476563, 25.978021621704	,
13.400478363037, 96.889030456543, 25.632938385010	,
-14.597910881042, 96.915992736816, 25.233594894409	,
-24.990398406982, 104.102752685547, 21.191919326782	,
-10.209653854370, 85.701484680176, 23.697591781616	,
-30.203418731689, 91.676643371582, 15.664257049561	,
-22.208415985107, 86.889137268066, 19.291431427002	,
9.388739585876, 85.680946350098, 23.697591781616	,
21.388362884521, 86.843482971191, 19.291427612305	,
29.393363952637, 91.614227294922, 15.664251327515	,
-23.771579742432, 122.071159362793, 15.888832092285	,
-24.958293914795, 134.757904052734, -4.182777404785	,
-30.173702239990, 120.048263549805, 10.701600074768	,
24.206382751465, 104.051246643066, 21.191915512085	,
10.240983009338, 135.573089599609, 5.012732982635	,
23.025207519531, 122.022155761719, 15.888828277588	,
29.018505096436, 115.612152099609, 15.126260757446	,
29.423488616943, 120.384887695313, 10.699300765991	,
24.238483428955, 134.706420898438, -4.182782173157	,
9.048435211182, 142.691345214844, -9.427839279175	,
-10.957406044006, 135.595275878906, 5.012733936310	,
-29.778289794922, 115.673721313477, 15.126267433167	,
-9.749954223633, 142.711029052734, -9.427838325500	,
-0.570982813835, 124.155982971191, -34.922500610352	,
-27.383609771729, 110.588394165039, -34.043918609619,
-20.564323425293, 129.002410888672, -30.549686431885,
-37.387737274170, 105.116149902344, -13.613405227661,
-35.001609802246, 91.879722595215, -19.537185668945	,
-24.204132080078, 90.992584228516, -32.731395721436	,
-0.590277791023, 105.731544494629, -39.216724395752	,
-15.416622161865, 79.053726196289, -20.663335800171	,
-0.606174826622, 90.551010131836, -35.929588317871	,
-36.201477050781, 91.998657226563, 0.861974120140	,
-36.585140228271, 107.613662719727, 3.571936130524	,
19.832458496094, 128.960083007813, -30.549694061279	,
26.613166809082, 110.531845092773, -34.043926239014	,
22.992649078369, 90.943145751953, -32.731403350830	,
34.193584442139, 91.807266235352, -19.537193298340	,
36.607433319092, 105.036201477051, -14.012453079224	,
35.810462951660, 107.938560485840, 3.570627212524	,
35.793697357178, 91.923271179199, 0.861968040466	,
14.581760406494, 79.022293090820, -20.663339614868	,
-12.221451759338, 74.438804626465, 12.162790298462	,
11.376938819885, 74.414093017578, 12.162788391113	,
33.003406524658, 101.199539184570, 13.608850479126	,
-33.391769409180, 101.269073486328, 13.608855247498	,
-25.356727600098, 136.258392333984, -21.392139434814,
-10.552977561951, 139.827514648438, -24.212800979614,
24.640052795410, 136.206054687500, -21.392141342163	,
9.845414161682, 139.806152343750, -24.212800979614	,
-30.584560394287, 109.682662963867, 16.760499954224	,
29.812217712402, 109.619415283203, 16.760496139526	,
-33.771049499512, 121.057899475098, -23.304393768311,
-35.770534515381, 121.543426513672, -8.508112907410	,
33.024127960205, 120.987953186035, -23.304401397705	,
35.024631500244, 121.469291687012, -8.508118629456	,
-38.090393066406, 198.084503173828, 6.129428863525	,
-44.103343963623, 185.711059570313, -12.442998886108,
-37.714534759521, 175.020263671875, 11.501019477844	,
-41.336219787598, 154.325775146484, -9.046323776245	,
-44.517784118652, 171.923919677734, -17.465534210205,
-38.936210632324, 154.333450317383, 8.571998596191	,
40.658958435059, 154.239913940430, -9.046331405640	,
37.080623626709, 174.941940307617, 11.501013755798	,
38.258968353271, 154.252609252930, 8.571990966797	,
43.877372741699, 171.831329345703, -17.465541839600	,
43.891796112061, 185.601806640625, -12.043226242065	,
37.504776000977, 198.005340576172, 6.129422187805	,
11.452414512634, 146.483779907227, 30.643775939941	,
-0.541894257069, 151.927734375000, 34.490413665771	,
-12.145978927612, 146.508499145508, 30.643783569336	,
-0.561097621918, 133.591796875000, 14.849332809448	,
20.241626739502, 137.708740234375, 11.832256317139	,
-20.955150604248, 137.751876831055, 11.832260131836	,
-18.947307586670, 145.245697021484, -30.273391723633,
18.251075744629, 145.206741333008, -30.273399353027	,
40.658958435059, 154.239913940430, -9.046331405640	,
38.258968353271, 154.252609252930, 8.571990966797	,
-41.336219787598, 154.325775146484, -9.046323776245	,
-38.936210632324, 154.333450317383, 8.571998596191	,
53.483078002930, 178.792602539063, -21.156089782715	,
53.467025756836, 163.465225219727, -18.641817092896	,
33.880470275879, 174.794326782227, -29.744762420654	,
-34.514713287354, 174.865951538086, -29.744750976563,
-54.110485076904, 178.905242919922, -21.156082153320,
-44.103343963623, 185.711059570313, -12.442998886108,
30.265655517578, 160.651931762695, -26.776130676270	,
43.891796112061, 185.601806640625, -12.043226242065	,
43.877368927002, 171.831314086914, -17.465541839600	,
-44.517784118652, 171.923919677734, -17.465534210205,
-54.126541137695, 163.577896118164, -18.641809463501,
-0.546090364456, 147.919784545898, 43.518653869629	,
-0.546290695667, 147.727539062500, 56.723060607910	,
-16.536712646484, 155.353958129883, 56.663722991943	,
-30.931118011475, 160.716018676758, -26.776126861572,
15.860198020935, 153.914337158203, 43.387752532959	,
11.862665176392, 156.274749755859, 35.487117767334	,
-12.535728454590, 156.300323486328, 35.487113952637	,
13.073184013367, 166.317321777344, 34.735744476318	,
9.481649398804, 174.403076171875, 33.096488952637	,
33.078235626221, 172.649444580078, 27.013450622559	,
27.483272552490, 177.467605590820, 26.829141616821	,
-0.510445952415, 181.956802368164, 43.445026397705	,
15.883250236511, 175.926757812500, 43.575210571289	,
-0.513783395290, 178.771621704102, 34.093639373779	,
-10.116743087769, 174.423599243164, 33.096488952637	,
-0.510227680206, 182.164215087891, 56.666545867920	,
15.883475303650, 176.135375976563, 56.797634124756	,
-16.515132904053, 175.960678100586, 43.575210571289	,
17.871925354004, 165.119079589844, 43.491401672363	,
17.872566223145, 165.725036621094, 56.731227874756	,
-0.518099606037, 174.648101806641, 63.536556243896	,
15.861670494080, 155.320007324219, 56.663722991943	,
-0.535291016102, 158.230499267578, 63.600730895996	,
26.300083160400, 193.522735595703, 25.948003768921	,
37.080623626709, 174.941940307617, 11.501013755798	,
37.504776000977, 198.005340576172, 6.129422187805	,
-0.542459309101, 151.393936157227, -42.809223175049	,
-37.714534759521, 175.020263671875, 11.501019477844	,
-26.896690368652, 193.578445434570, 25.948007583618	,
-38.090393066406, 198.084503173828, 6.129428863525	,
-28.113494873047, 177.525817871094, 26.829145431519	,
-33.716949462891, 172.719390869141, 27.013462066650	,
-16.514915466309, 176.169342041016, 56.797626495361	,
-18.526451110840, 165.157196044922, 43.491401672363	,
-18.525817871094, 165.763153076172, 56.731227874756	,
-16.538185119629, 153.948242187500, 43.387752532959	,
-13.725205421448, 166.345352172852, 34.735744476318	,
9.481649398804, 174.403076171875, 33.096488952637	,
-0.498224377632, 193.628463745117, 33.159080505371	,
-0.513783395290, 178.771621704102, 34.093639373779	,
-26.896690368652, 193.578445434570, 25.948007583618	,
-10.116743087769, 174.423599243164, 33.096488952637	,
-15.683876037598, 205.811798095703, 29.699726104736	,
-28.113498687744, 177.525802612305, 26.829145431519	,
15.114509582520, 205.779510498047, 29.699724197388	,
-38.090393066406, 198.084503173828, 6.129428863525	,
26.300083160400, 193.522735595703, 25.948003768921	,
27.483268737793, 177.467605590820, 26.829141616821	,
37.504776000977, 198.005340576172, 6.129422187805	,
9.481649398804, 174.403076171875, 33.096488952637	,
13.073184967041, 166.317321777344, 34.735744476318	,
33.078235626221, 172.649444580078, 27.013450622559	,
29.859703063965, 154.963226318359, 28.621461868286	,
11.862665176392, 156.274749755859, 35.487117767334	,
11.452414512634, 146.483779907227, 30.643775939941	,
-0.541894257069, 151.927734375000, 34.490413665771	,
20.241626739502, 137.708740234375, 11.832256317139	,
38.258968353271, 154.252609252930, 8.571990966797	,
-12.145978927612, 146.508499145508, 30.643783569336	,
-12.535728454590, 156.300323486328, 35.487113952637	,
-30.537078857422, 155.026473999023, 28.621463775635	,
-38.936210632324, 154.333450317383, 8.571998596191	,
-20.955150604248, 137.751876831055, 11.832260131836	,
-13.725205421448, 166.345352172852, 34.735744476318	,
-33.716949462891, 172.719390869141, 27.013462066650	,
-10.116743087769, 174.423599243164, 33.096488952637	,
-20.926685333252, 164.942123413086, -49.808761596680,
-0.542459249496, 151.393905639648, -42.809223175049	,
-14.538162231445, 153.980545043945, -55.505165100098,
23.467796325684, 162.694152832031, -54.311828613281	,
34.255950927734, 151.375869750977, -43.207984924316	,
26.658279418945, 153.609161376953, -57.122283935547	,
30.265663146973, 160.651931762695, -26.776130676270	,
20.270095825195, 164.898956298828, -49.808761596680	,
13.860233306885, 153.950805664063, -55.505165100098	,
33.880474090576, 174.794296264648, -29.744760513306	,
18.251079559326, 145.206741333008, -30.273397445679	,
-24.128993988037, 162.744003295898, -54.311813354492,
-27.338500976563, 153.665710449219, -57.122276306152,
-30.931121826172, 160.716018676758, -26.776126861572,
-34.939235687256, 151.448333740234, -43.207977294922,
-18.947311401367, 145.245697021484, -30.273393630981,
-23.749984741211, 142.698822021484, -44.802181243896,
-34.514717102051, 174.865921020508, -29.744752883911,
23.046806335449, 142.649841308594, -44.802188873291	,
-49.697925567627, 190.900604248047, -29.827302932739,
-30.085105895996, 204.658737182617, -42.421482086182,
-19.701747894287, 188.763107299805, -63.154010772705,
-44.103355407715, 185.711044311523, -12.442997932434,
-53.675426483154, 212.385864257813, -8.843883514404	,
-34.514717102051, 174.865921020508, -29.744752883911,
-20.520591735840, 170.764068603516, -63.562076568604,
-20.926685333252, 164.942123413086, -49.808761596680,
19.096645355225, 188.722457885742, -63.154010772705	,
19.876201629639, 170.721740722656, -63.562076568604	,
20.270095825195, 164.898956298828, -49.808761596680	,
49.095649719238, 190.797103881836, -29.827304840088	,
29.511672973633, 204.596359252930, -42.421489715576	,
33.880474090576, 174.794296264648, -29.744760513306	,
53.118144989014, 212.273986816406, -8.843892097473	,
43.891807556152, 185.601821899414, -12.043226242065	,
-38.090400695801, 198.084487915039, 6.129428863525	,
-15.683877944946, 205.811782836914, 29.699726104736	,
-26.485485076904, 204.288253784180, 46.047321319580	,
-12.875550270081, 213.763717651367, 30.857990264893	,
-28.051109313965, 237.111373901367, 19.493537902832	,
-16.842002868652, 245.803894042969, -4.939764976501	,
37.504783630371, 198.005325317383, 6.129422187805	,
27.545677185059, 237.053146362305, 19.493534088135	,
16.356395721436, 245.769134521484, -4.939768314362	,
12.322843551636, 213.737319946289, 30.857986450195	,
25.911304473877, 204.233383178711, 46.047313690186	,
15.114513397217, 205.779495239258, 29.699724197388	,
-0.444782137871, 244.661941528320, 29.042491912842	,
-0.483754813671, 207.443878173828, 55.398872375488	,
27.545677185059, 237.053131103516, 19.493534088135	,
12.322843551636, 213.737319946289, 30.857986450195	,
37.504783630371, 198.005325317383, 6.129422187805	,
-12.875550270081, 213.763717651367, 30.857990264893	,
-0.444782137871, 244.661941528320, 29.042491912842	,
-28.051109313965, 237.111358642578, 19.493537902832	,
-38.090400695801, 198.084487915039, 6.129428863525 };

Model marioModel;

/////////CUBE
Vec3 cubeOneFTL = { -1.0f, 1.0f, -1.0f };
Vec3 cubeOneFTR = { 1.0f, 1.0f, -1.0f };
Vec3 cubeOneFBL = { -1.0f, -1.0f, -1.0f };
Vec3 cubeOneFBR = { 1.0f, -1.0f, -1.0f };
Vec3 cubeOneBTL = { -1.0f, 1.0f, 1.0f };
Vec3 cubeOneBTR = { 1.0f, 1.0f, 1.0f };
Vec3 cubeOneBBL = { -1.0f, -1.0f, 1.0f };
Vec3 cubeOneBBR = { 1.0f, -1.0f, 1.0f };

std::vector<Vec3> cubeVerts = {cubeOneFTL, 
								cubeOneFTR,
								cubeOneFBL,
								cubeOneFBR,
								cubeOneBTL,
								cubeOneBTR,
								cubeOneBBL,
								cubeOneBBR};

bool init()
{	
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "Software Renderer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
	}

	SDL_SetHint(SDL_HINT_VIDEO_HIGHDPI_DISABLED, "1");

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL)
	{
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}

	myDraw::renderer = gRenderer;
	return success;
}

void close()
{

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main(int argc, char* args[])
{
	std::vector<Vec3> marioVerts;
	for (int i = 0; i < mario.size(); i += 3)
	{
		Vec3 newVert = { (float)mario[i], (float)mario[i+1], (float)mario[i+2] };
		marioVerts.push_back(newVert);
	}

	marioModel.vertices = &marioVerts;
	marioModel.position = { 0.0f, -150.0f, 250.0f };
	marioModel.rotation = { 0.0f, 0.0f, 0.0f };
	marioModel.rotationVelocity = { 0.0f, 0.01f, 0.0f };

	renderer.addModel(&marioModel);
	
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		float xAngle = 0.0f;
		float yAngle = 0.0f;
		float angle = 0.0f;

		//for (int i = 0; i < 100000; ++i)
		//{
		//	Vec3 vert = {RandomFloat(-2.0f, 2.0f),
		//				RandomFloat(-2.0f, 2.0f),
		//				RandomFloat(-2.0f, 2.0f)};

			//	renderer.addVert(vert);

			//}
			/*renderer.addVert(&cubeOneFTL);
			renderer.addVert(&cubeOneFTR);
			renderer.addVert(&cubeOneFBL);
			renderer.addVert(&cubeOneFBR);
			renderer.addVert(&cubeOneBTL);
			renderer.addVert(&cubeOneBTR);
			renderer.addVert(&cubeOneBBL);
			renderer.addVert(&cubeOneBBR);*/

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					if( e.type == SDL_KEYDOWN)
					{
						if (e.key.keysym.sym == SDLK_w)
						{
							xAngle += 0.01f;
						}
						if (e.key.keysym.sym == SDLK_s)
						{
							xAngle -= 0.01f;
						}
						if (e.key.keysym.sym == SDLK_a)
						{
							yAngle += 0.01f;
						}
						if (e.key.keysym.sym == SDLK_d)
						{
							yAngle -= 0.01f;
						}
					}
				}

				//Draw
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(gRenderer);
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);

				////////CUBE (CAMERA)////////

				renderer.render();

				angle += 0.005f;
				//renderer.setCameraRotation(angle, angle, 0.0f);

				SDL_RenderPresent(gRenderer);

				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
			}
	}

	//Free resources and close SDL
	close();

	return 0;
}