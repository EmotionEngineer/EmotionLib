#include "../include/mlp_model3.h"

static int model3_sizes[] = {53, 22, 3, 18, 1};

static double model3_biases1[22] = {-0.3635368595104663,0.6417311692772062,-0.15817850023703434,-0.8530204875295014,-1.6213217576795573,-0.729599279418629,0.04198818397730053,-0.3046277770496832,-0.32468082898071526,0.3259044966407041,0.4184644266863421,3.500129613252775,-0.4459682571589386,0.28163200174048136,1.072957804403069,-0.19817495281699568,0.08771396537205231,1.3395562271991983,-0.45298078160558325,-0.17975597002431604,0.6703680865080579,-0.9804797464895416};
static double model3_weights1[1166] = {0.6622228881853972,-1.9594693891493187,-1.094109625156373,0.21693680180773964,-1.595023522907505,0.6886760553603459,-0.15178431677523793,0.14422802680137398,-0.3109786794742151,0.7489294939232602,0.24799327381475392,1.9867461717461585,0.4356056849085207,-1.1907518933918844,-1.4842818384499128,1.1122204758395742,-0.011205129206223467,0.2972285325124806,0.27627497459920636,0.375128303609748,-0.3518902127161788,0.5106253323803359,-0.10745714839686007,-0.2074139787799991,1.6948530590190867,0.48974953298605844,0.054722855565069756,0.8157300756103144,-0.5834198642378451,-1.9034654879073258,0.40276996286450817,-0.48342204600601935,-0.21168369807721563,-1.5705353182167276,-0.08843878978757087,-0.08577678953402094,-0.23368720538559176,0.0280754481329799,-0.3443256853937355,-0.19775265333257988,-0.18296006667575712,-0.5400252375444816,-0.6619327298159776,0.08528318624730438,-0.749886252285756,0.13079228813835836,-0.2003169245456181,2.097614006643752,-0.2573502441482232,-1.2877393920378486,-0.4922058795079688,-0.46276256448632036,0.595134323421331,0.1722060428477852,1.1289186337586583,1.3105266198252232,-1.1521193017381703,-2.0021738661705153,1.4338909610901422,0.6317401368544437,-1.252555917731375,1.2397630770453165,-3.386459792086979,-0.533957804549573,-2.478028183266706,-1.1593235295060351,1.7062633180832327,0.5203616008664338,3.677686836943756,1.5140463887963025,3.860670413016944,-1.7097595640647574,-1.1609008720253289,-3.540372489653548,3.0999047902005405,1.4199262109246198,-1.5033308550417919,-3.466103741856327,-0.9925874257680796,0.6006601331001992,-0.3353502283046808,3.047416897948846,-4.440929763398851,3.2326431742629804,-1.8913800276009198,-0.5428460437438797,-2.1875347145514734,-1.6510158024176664,-1.3350531542547965,0.7746255958382602,-2.0604876230921043,1.0827913126830206,-3.420330247437967,2.199986708493683,0.08960589581285479,-0.5456486019093737,0.8292702313260158,-1.0060583924572244,0.8567495096750951,2.1730176709494966,0.6291396577471488,-1.28366009422378,-0.7438058465235873,-1.1203100424649448,2.12495139014885,-4.509319547743487,0.8544640404064874,0.2445715380335093,-1.1356465601382868,0.29030782539449224,-0.1098245204810325,0.0814559672332802,4.389287798855755,1.076130568034054,1.4208341093531385,-0.2958169193132252,-0.8336973474277486,-2.8202037345770954,1.9137335058206222,0.2717099440654886,0.10110610439463588,-3.5950200166149306,-0.8601689448099146,-1.015631236750995,0.5941714490579744,0.925271455848309,-1.5307809219127262,1.3068208207334038,-1.7412340512704005,-1.0067160745574422,-1.4767459252429853,-0.4915560853177788,0.1338735316503558,-0.18691122672898,1.7250579109963164,0.44806919540403456,1.7435103094527062,-0.02087683616327299,-0.5139564748292706,-1.1126257594288331,0.3254805358976014,0.11603848635722605,-0.4566607810126511,-3.7795432663271975,-0.32177930368614727,0.0040316548834277745,0.15563892236338236,-0.043362377458858535,-1.1761076412447724,0.1429993401995474,1.191154409740635,-0.17811526890333573,-0.07028577173735856,-0.41983201478678484,0.04243790004903215,-0.7901953505340412,0.05502178296138827,-0.29362709111375196,-1.8468324746149167,2.455793133042894,-0.7980260656785239,-1.2669711594526227,-0.967182535700955,-1.6143885263618065,0.06955620905525241,1.6281261945586332,0.08988516322232384,0.034288335418291536,-0.6861946288412532,-0.1973410936237634,0.37300176198108126,-0.9179543453763307,-0.6045829438804928,-0.8696651341341626,-0.6497925787473762,0.2453450518882514,1.1229041315051906,0.2553706519422764,2.2375894050199245,0.6677264384993813,3.1989980625653347,-1.9455620228802353,-0.2263006553612604,-0.7523090809037504,2.6120401535830537,1.3098258522086468,-0.6043550605355674,-2.785081559510067,-0.3548784865211212,-0.9229657525689908,0.1242523352258948,1.9883416741736033,-3.791789794023521,2.401375264160626,-1.6620381229102867,0.012337537891109671,-1.8519621190325772,-0.7079151702819511,-1.0140093285019367,0.5775565632977105,-2.181261245838074,-0.10779145527752079,-0.40337993494798163,0.5719587974103758,0.45632586006326525,1.9488290299668936,-1.2380499457975611,0.1491707805806356,1.1063160238493768,0.27398022503917074,0.04851259812429864,-0.2926126838552962,0.7538953444819363,-2.205226842314608,3.215255216559318,-1.4514110619324174,2.230491668211851,0.23449323558021704,1.385345470575081,-0.11351734614577302,-1.5214384860812722,0.42836743201580535,-2.317693978902125,-1.2071058228215559,-4.0177539589378695,2.0653178905961567,0.3414804494348828,0.10391558828617224,-0.23401350703958723,-1.0493686386037528,1.6300992236031153,3.8596789586235722,0.8752969699215757,-1.193424210856945,-1.4725418178977803,-0.6310008580919684,0.3138152355746466,-3.0366156595576026,1.200561928566777,-0.5471842755015199,1.4136602768904918,1.3427262826084865,-0.3561824904997586,0.36033068563003734,1.4480984366935103,-0.3774148539179496,0.36084787700597676,1.1444893457507963,-0.9047350344113976,-1.2304648330304535,1.0275616169367865,-0.11362463633811937,1.104364048387254,-2.0207339960452866,-1.6716133047610686,-1.1359643394839622,-0.771344043215019,1.0942757401123424,-2.0553673689337915,3.060358451799177,-0.9603127850113586,-1.612512586076388,-0.08529514765133232,-1.1780147669145744,0.9128535023324577,-0.14138121245239568,1.335627549705963,0.1980426365765979,-0.5311868851016212,-0.6309478683557949,-0.48744285000362386,-0.5847581340908844,0.61286809360896,0.28148375243224716,0.09308560799314104,-0.34846470389212947,-0.12573751431375144,-0.826138238870751,-0.5501322918519368,0.6828674964745074,0.540039718376411,-0.9848610044627925,-0.15999224684473373,-0.2361153838846007,0.12671912095173063,-0.9738440656363573,2.139018738122766,-0.5525022681337107,0.7917126509547047,0.5025928879083781,0.700654256362208,-1.5177456497956558,0.09902063841633928,-1.773555134919119,0.6800971110792879,0.648073849800907,-2.309806934758422,-0.5206102001987939,0.5988278080442858,1.521402347622073,-0.18604655823693358,1.8959499943875426,-3.3871466889285107,0.8410587911799475,-2.430806344791338,1.1845574510862782,-1.9356806430701141,0.41795740862828873,-1.662587004893514,0.2619443474434133,-2.222149489614564,0.6922956935882976,-1.2307669966591133,1.5841839841842646,0.3966476639787311,2.3322305862215167,-1.5856330556368796,-0.42607214973075536,1.5936164267748965,0.5843205713589783,-0.27453822562943275,-1.3423463785066332,0.3242128105465895,-1.8888262963706455,3.9733464819428854,-1.372582493313334,2.5528645036175983,-0.33586337881231865,1.768366344479654,-0.7116438046302968,-1.3183729615126296,0.5074573716126085,-0.233973892091657,-1.6281280408837724,-0.9058115477719677,1.0684554525949088,0.14048267465128209,0.2142884255478655,0.29652688289983536,-0.7465321191694475,1.5365803754153673,1.7732494291726293,-0.12336818274879921,-1.0951436685304032,-0.20130289339646987,-0.8361908508311153,3.009531398097417,-0.002677562929069072,0.8509215318961837,-0.6538986007004899,1.3518745681175086,0.8066201554164882,-1.0648479205634005,-0.18561379438494865,-3.248435479821709,-0.5041575451098761,0.4637303015374457,2.3789180184766567,0.22042593289232895,1.5263123562961607,-1.2200232582833452,-0.9296483290397968,0.24865318181755935,0.6567003696408237,1.6876954157195951,-2.247996234955431,0.07755348612761379,-2.27671543038921,6.6852253436006945,0.7751553745061912,1.863702003276751,-0.6420617546355084,1.3988269295774902,1.1328058948175352,-0.7345483326524994,-0.8211728190765457,-0.33667559297519506,-0.417111584535981,-2.5102427179308724,1.7245165035187717,-0.07760987088328052,1.7222509535089014,-1.7246928609094103,-1.1958364365641254,0.1755112858760323,3.094715248072572,-0.3922787508183783,-2.3837023582806696,0.24469236595662608,-0.9987251444130705,2.0679729712995423,-1.7204843582420335,1.628855098875381,-0.4075417590465135,0.983932719696406,-0.39422673981324247,0.7287052412529736,0.18761074497621488,0.1355792466984444,0.254412221531829,3.457401198729923,-0.18866362418663823,-0.7758526836110918,-2.4990393476860446,2.6250557714885834,0.03604717458929263,-0.8586405929857709,-4.238544877980385,0.5727817615939278,-1.9157226126542446,0.11409235404310161,1.2633430098121534,1.1821563992139439,4.05400004832055,-2.2562566621920954,-0.7614529219492946,-1.5918507715224781,0.34179932719627093,1.5768647641983016,-0.3337162427441791,1.6645627143242823,1.1868933463816378,2.3055224842167874,-1.3618899615193012,-0.08159811275143597,-0.7823958320607561,0.4473496149743176,0.7630262519345757,-1.460125663667103,-1.0797872504527075,-1.8226162167507913,1.149896619822777,0.9508353007445663,1.6344860276466968,-2.4697807618605956,0.9084209080557414,-2.2469024556148613,0.7089695738250112,-0.9229426322051527,-1.4248130343511247,-0.8574128579320153,0.35968094169811093,-3.0482079819407537,-0.4690638495266022,-2.0718585115970374,1.0268805003863055,0.6452664661712195,0.8325340455108483,-1.1565890348709427,-0.6889223296397733,0.8963954882343326,3.1431727058242815,0.4447535551939551,0.3836911363439293,-0.43582220661847354,-0.4832432581331668,2.284198974346826,-1.0017769075377123,1.3277752399968787,-0.2216338267488065,1.3721525981270357,0.6194424011095828,-1.0686927358831193,0.8237309581887083,1.7389087061763848,-0.759357294225055,-0.3696896686332843,0.11389766485969785,-0.057640605513787316,1.017794488107828,-1.038131274484619,0.5569689643460802,1.8575540206149166,1.5222781055148875,-0.1708087226457622,-0.5583932658133542,0.3612926791528072,-0.7444178500166324,1.0847945333357776,-0.26645319675869356,1.3100937340470615,-0.2910285195569094,1.394669165786462,-0.4018287332299529,0.6275859731137732,0.129514468262002,1.3760899464282805,2.111098181673279,3.372214505080093,-0.04953650404543145,-0.11244075050766014,-0.49484803790547466,0.866777585151682,0.7374608453691507,-1.314785120658766,-1.1274022221510287,0.11368495407877358,-1.236650827273701,0.8902877090185938,0.29108082602013335,1.6708008192034145,2.0711915956703653,-1.4838860145090638,0.5446614814703488,-0.855249669028288,-0.2762157973168586,2.1633202306097745,0.07821859964517998,4.173461127971345,1.9598232889284375,2.65888404599252,-2.002849767725191,-1.411413313410396,-3.5972273791714513,2.9607009433706706,0.45917527180366235,-2.1868793612872595,-1.0525177723377641,-1.148739993632923,-1.6105410710802983,0.783876659263106,3.715641824903196,-7.296283634900452,3.091737468503266,-3.1152141138057674,-0.8412675051171791,-3.3927651430423054,-2.277401949479048,-0.27822430333609366,0.6278697567586157,4.107513379074687,0.6014382673682388,1.0334015300250714,-1.3124518714522857,-0.5854249402458988,-1.9541984931474101,2.388303159912855,0.5094078716919171,0.3197458872097634,-2.4272814202352753,0.5703673776114364,-2.0270153125368866,-0.24585490906111018,1.109335511012861,-1.7614133492373831,2.9687638720850447,-2.3797800970472243,-0.6201752096041308,-1.3896237861596261,0.501857810672199,1.7242461378868164,-0.5979967908744637,-1.106936641284403,-0.1106184688766919,-0.05934809139081188,-0.5690176335635034,0.06472245078437418,-1.250134088819511,0.0690095383371445,0.04517854211994143,-2.0590925910451015,0.5847426106818995,0.9239767138889593,1.4368214891814122,-0.22228709981854058,1.1736692281852306,-1.4808495861106106,0.009271501885878388,-1.6608735655271012,0.9273501458136708,-1.1068835952211364,0.9420805470615801,-1.3830034232016502,0.40541255358368644,-1.9699919049067034,0.8959993862955317,0.03934931748940068,1.3688213292849523,0.1807517225092201,1.322165853660203,-0.6529216364378366,0.036938351464251756,1.3635879953036107,-0.9610264402253418,-0.16382776207495328,-1.0305342649017817,0.012538695428170505,-1.2557499768325777,2.3550204812218927,-0.45133083027209264,1.6502637812656151,-0.2577176898003627,0.7662605295365778,-0.5068483549894688,-1.476626796973545,0.30175554621620426,0.2643691087102955,-2.2281795237575825,-3.3897753613492156,1.3179085888528335,0.18807512656406372,0.809690932847686,-0.4125675542485994,-0.9713355811507827,1.7205868546779481,3.6617435421953437,-0.1675256295745184,-0.45913690105589317,-0.4574753821786008,-1.1634507866591812,2.075256629099004,-1.4232665729974947,1.6687981451316465,-0.6328971952466349,2.063665007223281,1.127788183264722,2.2937848751163648,-0.9376753189412803,-1.3975716387688637,-1.7019737630194827,-2.083289743131441,-0.9055718514330835,0.10984086829396987,-1.2634106804185028,-0.04239384380645342,-0.09311969380783847,-2.336477700287615,1.4716154376882011,0.9223447055164147,2.403980061587558,-0.6050048241718446,1.6352210077587186,-4.139158462831007,-1.5051117358130959,-2.0389015118734495,1.3123547461581282,-1.7687247100057844,1.4465474077574996,-0.8456135390078543,0.19369392499815635,-1.370198955544424,0.6184526591736734,0.39816911043446773,0.7300056101201469,-0.0723054965483979,0.6018225266258156,-0.028896349472803357,0.11383536956188085,0.918990184983892,-1.2938198396819953,-0.2921251884531968,-0.781864083248508,0.17477592183698956,-0.2743676071353862,1.6907283239494806,-0.04712102535337312,0.9880849398387276,-0.32454795872205977,0.44592144841092923,-0.2982676009767635,-1.5387788446313833,0.7879283618924613,0.5070467584478285,-1.2972091753078556,-2.1293175954813943,0.583058555771551,-0.019925091412947477,0.9586624957337861,-0.5782245820653386,-0.1796843251348505,1.962086446255323,3.1752677527438866,-0.6404143644423819,-0.8617509370208896,0.024746127619535985,-0.9558881216965209,1.2898681701162091,-1.1822358194798144,1.5883705837579467,-0.38903684163873214,1.6722074570037293,0.014822346355237947,1.5672470406246573,-0.5064284736225155,0.36307291474432757,0.8296661137141171,1.5833008026217836,-0.9733617108178407,0.1433972373881868,-1.3347804152576042,0.5038166271002276,0.3866531223226517,-2.2155219829312665,-0.9588778119168976,0.5917327768763027,1.012206633831001,0.1091509985174259,1.148040390726574,-1.0248118780446214,1.374391187581257,-1.8903843587970053,0.6223724198660567,-1.2615802340302131,0.2776411675581143,-2.6355801176618674,0.9105442527291283,-3.395735928343397,0.7382129449756675,-1.368678586606985,1.9881439820159765,0.5483122029565463,3.466449766134954,-2.1266775795547486,-0.19578299895201584,2.438565839518214,1.250868702900862,-0.03634605221141543,-1.28636567033102,0.11130107138683362,-2.808583239488678,5.067601363081358,-2.288463479399656,3.3195592354018686,-0.2450734261124427,2.597490631275058,-0.4378195382242413,-1.1896711546585512,-0.07811400377356206,1.0706766874772216,-1.579274141602409,1.9243029722070892,0.8105052004440297,0.15576218918421725,-0.5204164542533924,0.715856772386431,-0.5370042103388053,1.0939465253057963,0.0018599983289018904,0.06570032631775782,-0.8359274736722145,-0.3878753910861004,-0.5215593468612225,2.886585421680519,1.4137738612149182,0.37585649306529023,-0.6099316647518628,1.107807158880043,0.8270627731163669,-1.5804391148262276,0.7148059997105399,-1.5047331615472637,0.21465895842922136,-0.9845612810624854,1.0328020707437526,-0.05043354793509254,1.932990393833436,-0.7144901661406675,-0.49197511491257023,2.2476359646657675,1.8711990497950715,-0.593990032472156,-2.193237040166468,0.5811532193671035,-1.907356550918282,5.015862259945265,-1.3638695648606163,2.6302171462728303,-0.496511767735164,2.04551802899075,-0.3994037859655766,0.926101038258219,1.253350119384686,3.0459577115279757,-0.36231201140251745,1.1951876079623076,-1.4502552626697514,-0.7841991564475689,-1.9557850288087624,2.934087963944069,1.0848295632458285,-0.660201161136782,-1.7892282554737398,-0.07133882761662752,1.8555264519304133,-0.31681381005578835,2.3802754827944717,-4.432766130476903,2.1422005777802102,-2.9381207945391035,0.31232841575917575,-2.703552264135045,-0.07775573441692125,-0.31949760186345993,-0.6384653212539555,-0.14814696585074322,0.22337441047375695,-0.07254173294076871,-0.8797784188274933,0.06429303088892178,0.8513750445750289,-0.7503537798687027,-0.1814771031157476,-0.09761459500779146,-0.8909571246360097,-0.15233117160433238,0.5988967942930931,-0.9517089946599809,-0.29927898143607096,-0.43597697480550257,0.3838322224952142,0.0294028803962632,0.06182959132867303,0.2635683494153185,0.6992425049431816,-0.15796055495387423,0.08123964970517353,0.09081450713641406,-0.19297474429630954,0.09108772042126369,0.15794608264481586,0.33082638815459847,0.6638876063140061,-0.16200285670018022,-0.008756767967901941,0.9758327084079528,-1.034947096011697,-0.09717914257973015,-0.5112237486805896,0.07362493567945758,-0.9015666861880232,0.7028000966654933,-1.3182510891554065,0.8232380906592662,-0.12043678631002147,0.8882116430627087,0.205314381382018,0.09822607567847066,2.2746667830807543,0.6602477536726487,-0.7435526720590668,-1.6789720502571246,0.05767121392507127,-0.4139719237931908,0.8611775109717071,0.605908341097059,0.5424243863932838,0.28829547685749474,0.7092971643541731,0.0762747787435913,2.541084696682205,-0.2797028380839861,0.4985427335933729,-1.3290466638630154,0.7771576928389002,-0.3648453187858352,-0.232011570057275,-0.6818422028749744,0.030489963324969612,-0.1945076272748822,-0.4608221114194176,0.07155897373043602,0.1882708588889354,-0.39440279987978716,-1.0601848123591837,-0.24105130162818109,0.36855653666576627,-0.5210968066460939,-0.40181378179340305,0.13398045681817453,-0.10798396186629333,-0.48078384241593275,0.3403653965664131,-1.1133576329274735,-0.40694591102946476,0.5016890335937084,0.29965024348953184,0.06480964114015103,-0.47902892688930665,0.3975999929634019,0.5701918587173685,-0.8611608126125687,0.5787780861630636,-1.2475421990984636,-0.42102347127025247,-1.870707141043279,0.33231657036404105,0.04289881513001858,-0.9564146095564817,0.30157677837973806,-0.3224905709330704,0.8201485888903007,2.043075658167183,0.5673930286378621,-0.9209942995234379,-0.7189088875348264,0.3485447159737428,-1.5073808811732443,-0.9105920609214335,-0.5472725710081213,-0.421564877276307,-0.045993162016330205,0.23801239292548387,-3.054412232224342,1.3095388213854167,-2.105221841784622,2.458408049067101,-2.002420194459664,-0.0024681957604654335,0.09566538745991139,1.2134804698020802,-1.3804279376321271,0.3945050979967204,3.1362397598340204,0.8098767234722989,-0.8343378741092473,-3.5721649405918394,1.3981282251604645,-1.6414947057779903,2.2400020445568716,-2.709752996832151,2.549461826730604,-0.4632861242368134,2.54956473604639,-1.2063442921872476,-1.5043950643727575,1.1373224319610553,-2.098297377752564,0.02479567892452479,-1.828359800082078,1.6251940496396244,-0.2552021783165952,-0.38799417230937044,0.8503360173709602,-0.5630295755584099,1.4494376984657065,2.739421557861106,-0.3671030338929125,-2.437617969269904,0.7226870226602373,-0.15907154769933152,0.6963788838063578,-1.8899667753331797,0.6367164234733401,-0.612677820846185,0.6481375736913751,-0.5018707514011982,1.0923235375981657,0.32318665524482354,1.0283544904793747,-1.1792693202186793,-0.7125521515519664,0.24047516118339418,-0.6504798234499103,-2.267907547595963,1.6097810450646488,-0.010936955921009692,-0.9250512423450843,0.6907121602087127,0.11001945889944047,-0.4020552434046462,-2.12702004110971,2.585161975819392,-4.745980427874749,1.6964217597924809,-1.786643100947241,-0.6927991050015924,-1.2357137618249083,0.42809501722271587,-1.8108667529582663,-0.11235979230567729,0.1650253507971568,0.30886197848418373,-0.21588719255037925,1.0377668849689157,0.1942086983131538,2.306183978547965,-1.370552113316765,-0.7178568076170198,1.850025165409508,-0.11296241255987274,-0.5650805634845244,-1.9858713901921883,0.33425470292279397,-2.317376235957094,3.2873861262780633,-1.5789105435765745,1.9877662680260415,-0.36865784299418286,1.8480446484415542,-0.10177582498503927,-0.5380956689488043,0.3574393687642144,-0.25588606017266774,-1.7328318982940547,1.151434240798906,2.578298874338159,-0.20372382077748785,-1.2393175250181478,0.7985488983603455,-1.1733927752952908,0.5685300765287096,0.555493812193726,0.7817849214231447,-1.3291954973135451,-1.1192900107351875,0.3347771677273929,0.3395294243569534,-1.3876657396148573,1.1306925201966236,-1.0211081445833843,1.2433366682104463,1.14031189481455,0.613898592217408,0.1750582157388648,-0.35852529990345805,0.2427028308594804,0.13330218448049375,0.8154063099956325,0.10306368626632133,-1.1738252717559066,1.031138073097722,0.627562240230721,-0.3097379206003434,3.016640974542474,1.49821184352184,-0.4459186633367728,1.301517422052952,1.2371402858929466,-0.5081420315839934,2.391894853703965,0.17950181621141215,0.2942809595652116,-0.7181785547322578,0.3453179528057339,-0.0482197373430355,-0.35246319756446215,1.1989050532691528,0.3722584007948046,1.5448058469473023,-1.6704271522199405,0.44321065701905993,2.538506370784088,-2.160542325684087,-0.6646416697883463,0.6575897428553711,4.732752344045486,-1.008594273032322,-0.0093908154984324,0.27841683164430364,-2.0256540201455655,2.31335930248329,-1.5939419632204728,-0.025849946945136707,0.01831370649317426,2.1491612404881413,0.1293622807512121,-0.5852190721398669,-0.08183615739335577,-0.5418311280515117,-0.35226826028146857,-1.619173979233903,0.5327530086428983,-0.24645167802996668,-0.827027090747609,0.5540432169735435,-0.19413770801457983,0.02031723405709032,-7.763222591952729,-0.9673956051646955,0.3629046244131534,-1.6992692419181896,0.09675633487277911,-1.4563735428464366,-1.6666976783419891,-0.11536156196030177,-0.28985808051277034,-0.9438955115052906,-0.6825509089308773,0.2182985146534827,-0.007939103263828327,1.3200348336344618,-0.9042317862420338,0.21161911413816595,1.2635778656900565,0.04643955378413013,-0.9284158425126373,0.058786499729526195,-0.3858936473557435,-0.44119910332672974,-1.834553222142305,0.49020714755778244,0.8740825382587142,-0.8700895418069812,-0.2331822735341877,0.24855083490004254,-0.8794601041339127,1.6113977982940861,-0.22122653707307333,0.9429905095542391,0.5072482012429043,2.118342506745898,-0.22434047322039466,2.6101133402841015,0.8145238940646132,0.4235061245084809,-2.51909058241671,-0.08349272363093296,-2.094378953223066,1.3595504777961158,0.9453756389223161,-1.8337677084160826,-0.7887927838706105,-0.5920717597095001,2.554006496039811,0.038686849963193895,2.85571888361515,-6.68577447413379,0.16983038570242076,-3.1161496846365675,0.9393673976075894,-2.225371720295298,-0.14145112206228658,0.6118911114516719,0.39913265432456696,1.6270068608850494,-0.6110101172623073,-0.07421219031856036,0.5433517991800856,-0.6602105376428826,-2.237668886493256,1.765156943560241,0.023454249173515882,-0.29421154198918226,-0.23573638592698176,-0.11331140720733553,-1.9576620040016517,-1.5318110492240677,2.149111378304907,-3.7879921081764527,1.3254663994691946,-1.0155028804768986,-1.0126668234840184,-0.6422576939172054,0.1063876276079844,2.851307353277522,-0.5933583431056677,4.527663801940519,-1.1401069079281645,1.006158449979939,-0.9279027197043412,-0.23123648578507774,-3.981924123284533,1.3184635122624415,-0.2723007041951811,-3.611072680679398,1.0102471269682944,1.284173957841116,0.11953675042890023,-2.3910385563469783,3.336621216091811,-6.494062992182826,0.26274301902494945,-3.0135159516528085,0.09022339639269517,-2.409377438081077,2.101422152955182};

static double model3_biases2[3] = {0.07558698305823569,-0.9952711301559407,1.1445511322203432};
static double model3_weights2[66] = {2.458351132686261,-0.17799015127492787,3.211623440292275,-3.3415517747329493,-0.31575408413054795,0.29570360534571627,-8.3283525325521,1.2349723536536432,-5.18598989600824,-5.632605643811933,-1.2267442596120963,-2.1180358240852812,-6.688011480777023,0.6457440877019867,-6.983905927870187,5.332951695954962,-1.518225755978516,2.0548195628717485,1.2650435964471882,0.866418840208639,-0.19146749569856086,1.0839800577079628,-1.3781020497107284,-1.7705846054648098,-4.437119040492661,-3.0505190181186586,0.23485806956165373,-2.5337911207767942,0.7128323119313924,-1.8481081487291353,-3.642562997136002,-0.5230522766279818,-2.1272691812182996,8.29217346366807,-1.4464306154518987,10.179144943972128,2.619873459967141,1.0877086990341982,1.268692356729268,8.575595849284781,-1.499567628629245,4.371450926989147,-2.769996286142459,-2.6552388366897604,-3.8831536797574335,-1.6286398275697669,-0.31756719350085233,1.5696370634235122,7.452188715509676,-2.480016618728831,1.8418940736890093,-8.204754343846464,0.44119680412594486,-2.542956335513858,4.350082761715385,-0.06251100811358358,0.7795278931091371,1.4872853292091366,-1.1605320334437645,-2.9791907544081355,2.4874864675078183,-0.5514064428983994,0.06924327100461321,3.5172741657587148,2.7567377606587553,0.8483755449977778};

static double model3_biases3[18] = {0.29857476979394065,0.036760551699792525,0.8607450239743333,-1.0160086527043457,0.529804867081481,1.5764400016198181,0.321487302240725,-2.01863867398516,-0.25018811830199367,-0.9819175219423327,-0.7925020713643243,0.03892573277616835,-0.04808648308043582,-1.4078316373966742,0.4802207370380222,-0.4162052322112015,0.11260329663693154,-0.38080553486594815};
static double model3_weights3[54] = {-0.23904577741291508,0.9957023169944101,2.226168521527307,-1.339253756391969,4.264920016353072,3.703983187782728,1.149869009910298,-1.9706284393339724,1.2067430348364627,-2.3399623677579173,-3.106526487645812,-1.8150070880855282,-0.4792861512457947,3.1397287673541183,2.5855417084347376,2.298009630329556,0.010955805813355342,0.43718000043288546,-0.6045107909862291,-0.38662491160029805,-1.7179333432565567,-0.6113218756540915,-1.6653449643140683,-2.177876854837086,-0.372487918576526,-1.1873175175860127,-0.752552987050859,-0.10461164173894238,1.2055867784395828,0.35478132081755714,0.11815359608729516,-2.2376597422388445,0.8146809710709186,-1.1300421457934926,-0.1366666389572418,-0.010930118441209736,-0.17410272406137828,0.6353651456691609,1.615816946863566,-0.5936250171339976,2.804510120869832,3.2262208415380287,0.7660669880104307,-0.6551789603183608,1.0833357350912285,-1.109963964551353,-2.1884773198362826,-0.41496377242836113,-0.15061626669313766,1.1275857113353904,1.3719986876617623,1.433161754830528,0.1707902757543066,0.2903126504525996};

static double model3_biases4[1] = {0.026436902897266603};
static double model3_weights4[18] = {1.396809066720373,-0.8433163389101823,-2.6958424233693443,-0.852299496463171,-0.05411629777599931,-2.4768429040874103,-0.7148130282979013,-4.103139427363853,0.07944121838593446,-0.7150303065035455,0.9638146381419741,2.931268549964586,0.539059207432032,2.5201060517246603,3.779287609240923,0.8779129458413848,-0.037687870373806026,-0.9120852240521257};

static double *model3_biases[] = { model3_biases1, model3_biases2, model3_biases3, model3_biases4 };
static double *model3_weights[] = { model3_weights1, model3_weights2, model3_weights3, model3_weights4 };

MLPModel model3 = {5, model3_sizes, model3_biases, model3_weights};