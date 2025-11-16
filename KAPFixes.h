#define NUMBER_OF_FIR_BOUNDARY_FIX_LIST 23
CPosition fir_boundary_fix_list[NUMBER_OF_FIR_BOUNDARY_FIX_LIST];
CPosition *ADNUR;
CPosition *AGAVO;
CPosition *ANDOL;
CPosition *APELA;
CPosition *ATOTI;
CPosition *BEDAR;
CPosition *BESNA;
CPosition *GOLOT;
CPosition *IGRAS;
CPosition *INVOK;
CPosition *KALEK;
CPosition *KANSU;
CPosition *LAMEN;
CPosition *LANAT;
CPosition *MESOV;
CPosition *MUGUS;
CPosition *ONIKU;
CPosition *RIVAT;
CPosition *RUGMA;
CPosition *SAMDO;
CPosition *SAPRA;
CPosition *TOMUK;
CPosition *VASRO;

void InitializeFirBoundaryFixes() {
    ADNUR = &fir_boundary_fix_list[0];
    fir_boundary_fix_list[0].m_Latitude = 42.208325;
    fir_boundary_fix_list[0].m_Longitude = 130.8027888888889;

    AGAVO = &fir_boundary_fix_list[1];
    fir_boundary_fix_list[1].m_Latitude = 37.166666666666664;
    fir_boundary_fix_list[1].m_Longitude = 124;

    ANDOL = &fir_boundary_fix_list[2];
    fir_boundary_fix_list[2].m_Latitude = 37.66611111111111;
    fir_boundary_fix_list[2].m_Longitude = 133;

    APELA = &fir_boundary_fix_list[3];
    fir_boundary_fix_list[3].m_Latitude = 34.723055;
    fir_boundary_fix_list[3].m_Longitude = 129.23333305555556;

    ATOTI = &fir_boundary_fix_list[4];
    fir_boundary_fix_list[4].m_Latitude = 30.00355777777778;
    fir_boundary_fix_list[4].m_Longitude = 125.19815694444445;

    BEDAR = &fir_boundary_fix_list[5];
    fir_boundary_fix_list[5].m_Latitude = 31.900277777777777;
    fir_boundary_fix_list[5].m_Longitude = 126.48611111111111;

    BESNA = &fir_boundary_fix_list[6];
    fir_boundary_fix_list[6].m_Latitude = 34.62166666666667;
    fir_boundary_fix_list[6].m_Longitude = 129.13083333333333;

    GOLOT = &fir_boundary_fix_list[7];
    fir_boundary_fix_list[7].m_Latitude = 40.208333333333336;
    fir_boundary_fix_list[7].m_Longitude = 124.50833333333334;

    IGRAS = &fir_boundary_fix_list[8];
    fir_boundary_fix_list[8].m_Latitude = 37.312576111111106;
    fir_boundary_fix_list[8].m_Longitude = 132.7362372222222;

    INVOK = &fir_boundary_fix_list[9];
    fir_boundary_fix_list[9].m_Latitude = 34.78860944444444;
    fir_boundary_fix_list[9].m_Longitude = 129.32296944444445;

    KALEK = &fir_boundary_fix_list[10];
    fir_boundary_fix_list[10].m_Latitude = 35.208888611111114;
    fir_boundary_fix_list[10].m_Longitude = 129.88472222222222;

    KANSU = &fir_boundary_fix_list[11];
    fir_boundary_fix_list[11].m_Latitude = 38.63333333333333;
    fir_boundary_fix_list[11].m_Longitude = 132.475;

    LAMEN = &fir_boundary_fix_list[12];
    fir_boundary_fix_list[12].m_Latitude = 31.610000000000003;
    fir_boundary_fix_list[12].m_Longitude = 124;

    LANAT = &fir_boundary_fix_list[13];
    fir_boundary_fix_list[13].m_Latitude = 36.3732375;
    fir_boundary_fix_list[13].m_Longitude = 131.4283172222222;

    MESOV = &fir_boundary_fix_list[14];
    fir_boundary_fix_list[14].m_Latitude = 38.63333333333333;
    fir_boundary_fix_list[14].m_Longitude = 130.46666666666667;

    MUGUS = &fir_boundary_fix_list[15];
    fir_boundary_fix_list[15].m_Latitude = 30.001666666666665;
    fir_boundary_fix_list[15].m_Longitude = 124.95333333333333;

    ONIKU = &fir_boundary_fix_list[16];
    fir_boundary_fix_list[16].m_Latitude = 32.194934999999994;
    fir_boundary_fix_list[16].m_Longitude = 126.65470444444445;

    RIVAT = &fir_boundary_fix_list[17];
    fir_boundary_fix_list[17].m_Latitude = 41.483333333333334;
    fir_boundary_fix_list[17].m_Longitude = 132.26666666666668;

    RUGMA = &fir_boundary_fix_list[18];
    fir_boundary_fix_list[18].m_Latitude = 32.50334027777778;
    fir_boundary_fix_list[18].m_Longitude = 126.96472416666667;

    SAMDO = &fir_boundary_fix_list[19];
    fir_boundary_fix_list[19].m_Latitude = 33.58414916666667;
    fir_boundary_fix_list[19].m_Longitude = 128.3157688888889;

    SAPRA = &fir_boundary_fix_list[20];
    fir_boundary_fix_list[20].m_Latitude = 35.823835;
    fir_boundary_fix_list[20].m_Longitude = 130.72357583333334;

    TOMUK = &fir_boundary_fix_list[21];
    fir_boundary_fix_list[21].m_Latitude = 38.71666666666667;
    fir_boundary_fix_list[21].m_Longitude = 124;

    VASRO = &fir_boundary_fix_list[22];
    fir_boundary_fix_list[22].m_Latitude = 42.46388888888889;
    fir_boundary_fix_list[22].m_Longitude = 129.74027777777778;
}

#define NUMBER_OF_FIX_LIST 1109
CPosition fix_list[NUMBER_OF_FIX_LIST];
CPosition *JOOKA;
CPosition *ANOTI;
CPosition *VEMPU;
CPosition *CASTO;
CPosition *OLTOV;
CPosition *POLLU;
CPosition *ANKEG;
CPosition *VEMTI;
CPosition *ENDEX;
CPosition *IKOSU;
CPosition *DOXEL;
CPosition *KORHA;
CPosition *OLSAX;
CPosition *DUBAL;
CPosition *OLGOD;
CPosition *ORINU;
CPosition *AD020;
CPosition *AD050;
CPosition *ADGES;
CPosition *AGBIS;
CPosition *AGSUS;
CPosition *AGUTI;
CPosition *AKARA;
CPosition *AKBIN;
CPosition *AKEVI;
CPosition *AKIAS;
CPosition *AKPET;
CPosition *AKUBO;
CPosition *AKLOG;
CPosition *PS241;
CPosition *PS242;
CPosition *PS243;
CPosition *PS244;
CPosition *PS151;
CPosition *PS152;
CPosition *PS061;
CPosition *PS062;
CPosition *PS603;
CPosition *PS604;
CPosition *PS421;
CPosition *PS422;
CPosition *PS423;
CPosition *PS424;
CPosition *PS426;
CPosition *PS482;
CPosition *PS581;
CPosition *PS582;
CPosition *PS583;
CPosition *PS584;
CPosition *PS681;
CPosition *PS682;
CPosition *PS683;
CPosition *PS684;
CPosition *PS781;
CPosition *PS782;
CPosition *PS791;
CPosition *PABKO;
CPosition *GOLOG;
CPosition *GUTVA;
CPosition *GIVOD;
CPosition *BUVPU;
CPosition *IGULO;
CPosition *BUPGU;
CPosition *AGTEG;
CPosition *BOTRU;
CPosition *VONDU;
CPosition *SOLYI;
CPosition *VIBOR;
CPosition *NOBOP;
CPosition *RUPIB;
CPosition *MAMVI;
CPosition *AURIO;
CPosition *OLNOB;
CPosition *FOKAN;
CPosition *GAFOA;
CPosition *AKPON;
CPosition *ALDON;
CPosition *AVMET;
CPosition *ANBOG;
CPosition *ANJAY;
CPosition *ANKIB;
CPosition *ANKOG;
CPosition *ANKUS;
CPosition *ANROD;
CPosition *ANSIM;
CPosition *ANUBA;
CPosition *AP140;
CPosition *APARU;
CPosition *APDOP;
CPosition *APITO;
CPosition *OLVAR;
CPosition *ARECO;
CPosition *ASORA;
CPosition *ATASO;
CPosition *ATIMO;
CPosition *ATINA;
CPosition *ATKON;
CPosition *ATLAX;
CPosition *AVNIS;
CPosition *AYEON;
CPosition *AZUKI;
CPosition *BAHDA;
CPosition *BAKJO;
CPosition *BANYA;
CPosition *BASEM;
CPosition *BATAP;
CPosition *BEDES;
CPosition *BEDOM;
CPosition *BEETL;
CPosition *BELTU;
CPosition *BEMGA;
CPosition *BEPKO;
CPosition *BEZEE;
CPosition *BIDBA;
CPosition *BIDRI;
CPosition *OPIBA;
CPosition *BIGOB;
CPosition *BIGTU;
CPosition *BIKLA;
CPosition *BIKSI;
CPosition *BILUM;
CPosition *BINIL;
CPosition *BINJO;
CPosition *BINOR;
CPosition *BIRIN;
CPosition *BIROB;
CPosition *BIROM;
CPosition *BITIM;
CPosition *BITUX;
CPosition *BLAZZ;
CPosition *BOBIB;
CPosition *BODEK;
CPosition *BODOK;
CPosition *BODOL;
CPosition *BOGAN;
CPosition *BOLUT;
CPosition *BONSO;
CPosition *BOPKI;
CPosition *BOPTA;
CPosition *BOREV;
CPosition *BOSPI;
CPosition *BOXOL;
CPosition *OPASI;
CPosition *BUGYO;
CPosition *BUKIL;
CPosition *BULGA;
CPosition *IDEVA;
CPosition *BULTI;
CPosition *BUMEP;
CPosition *BUMSI;
CPosition *BURIM;
CPosition *BUSKO;
CPosition *CAMAS;
CPosition *CAVOI;
CPosition *CD120;
CPosition *CELCA;
CPosition *CG050;
CPosition *CG100;
CPosition *CG101;
CPosition *CG130;
CPosition *CG200;
CPosition *CHANO;
CPosition *CHUJA;
CPosition *CIKRA;
CPosition *CK099;
CPosition *CK100;
CPosition *CONAR;
CPosition *CP101;
CPosition *ATNER;
CPosition *ANPEM;
CPosition *ASIDI;
CPosition *EMSOS;
CPosition *EXUTO;
CPosition *LAPOP;
CPosition *LEGOP;
CPosition *MABLO;
CPosition *NOKEB;
CPosition *UDIDA;
CPosition *VIMER;
CPosition *DABIK;
CPosition *DAEBO;
CPosition *VADRO;
CPosition *DAKPI;
CPosition *DALKA;
CPosition *DALPO;
CPosition *DALSU;
CPosition *VETUP;
CPosition *DANPA;
CPosition *DANTI;
CPosition *DC031;
CPosition *DC032;
CPosition *DC035;
CPosition *DC036;
CPosition *DC037;
CPosition *DE030;
CPosition *DE031;
CPosition *DH002;
CPosition *DH017;
CPosition *DH020;
CPosition *DH021;
CPosition *DH022;
CPosition *DH023;
CPosition *DH024;
CPosition *DH027;
CPosition *DH028;
CPosition *DH029;
CPosition *DH030;
CPosition *DH034;
CPosition *DH047;
CPosition *DODBI;
CPosition *DOGDI;
CPosition *DOHAE;
CPosition *DOKDO;
CPosition *DOKPA;
CPosition *DOMKO;
CPosition *DONPO;
CPosition *DONVO;
CPosition *DOOBU;
CPosition *PUMEG;
CPosition *DORTI;
CPosition *DOTOL;
CPosition *DOVRA;
CPosition *DOWAN;
CPosition *DRIPS;
CPosition *DRGGN;
CPosition *MUSTG;
CPosition *JULOP;
CPosition *JEWEL;
CPosition *CROUN;
CPosition *JADUB;
CPosition *MONRO;
CPosition *JERMY;
CPosition *CASPR;
CPosition *BEAMR;
CPosition *CELMU;
CPosition *WONLI;
CPosition *ZOBES;
CPosition *AVRIG;
CPosition *STNNN;
CPosition *JINEL;
CPosition *STOWT;
CPosition *VISEN;
CPosition *LAGER;
CPosition *KAYJE;
CPosition *VOKOT;
CPosition *CNNDY;
CPosition *OGBIE;
CPosition *JISOV;
CPosition *BANDT;
CPosition *HUVSU;
CPosition *BRREW;
CPosition *SOJUE;
CPosition *TIMAY;
CPosition *OSIKE;
CPosition *OSCOR;
CPosition *MOKLI;
CPosition *BOBAE;
CPosition *PLSNR;
CPosition *BRRRR;
CPosition *DT006;
CPosition *DT007;
CPosition *DT009;
CPosition *DT034;
CPosition *DT038;
CPosition *DT043;
CPosition *DU002;
CPosition *DU004;
CPosition *DU009;
CPosition *DU018;
CPosition *DU022;
CPosition *DUDOT;
CPosition *DU030;
CPosition *DU063;
CPosition *UPKIG;
CPosition *DUBAN;
CPosition *DUBUN;
CPosition *DUKAL;
CPosition *DUMAN;
CPosition *PEDVA;
CPosition *DY019;
CPosition *DY020;
CPosition *DY025;
CPosition *DY027;
CPosition *DY016;
CPosition *DY017;
CPosition *DY034;
CPosition *DY037;
CPosition *EG020;
CPosition *EG040;
CPosition *EG070;
CPosition *EG140;
CPosition *EG160;
CPosition *EGOBA;
CPosition *EGOMI;
CPosition *EKIVA;
CPosition *EKVIK;
CPosition *ELAPI;
CPosition *ELGEP;
CPosition *ELGUK;
CPosition *ELMAP;
CPosition *ELPEX;
CPosition *ELPOS;
CPosition *EMRET;
CPosition *EMTIK;
CPosition *ENBUK;
CPosition *ENGOT;
CPosition *ENPIL;
CPosition *ENSAL;
CPosition *ENSUM;
CPosition *ENTEL;
CPosition *ESBIS;
CPosition *ESBOS;
CPosition *ORUSA;
CPosition *GAEBI;
CPosition *GALDI;
CPosition *GAPHA;
CPosition *GAYHA;
CPosition *GAZIN;
CPosition *GC003;
CPosition *GC001;
CPosition *GC021;
CPosition *GC022;
CPosition *GC034;
CPosition *GC036;
CPosition *GC071;
CPosition *GC072;
CPosition *GE008;
CPosition *GE016;
CPosition *GE017;
CPosition *GE020;
CPosition *GE022;
CPosition *GE023;
CPosition *GE024;
CPosition *GE027;
CPosition *GE028;
CPosition *GE041;
CPosition *GE046;
CPosition *GEOJE;
CPosition *GH034;
CPosition *GODIS;
CPosition *GOMUX;
CPosition *OLRIB;
CPosition *GOGET;
CPosition *GOKAK;
CPosition *GASAN;
CPosition *GOMAR;
CPosition *GONAV;
CPosition *GONAX;
CPosition *GONEE;
CPosition *GONYA;
CPosition *GOSBO;
CPosition *GOSIM;
CPosition *GOURA;
CPosition *GOVLI;
CPosition *GT006;
CPosition *GT007;
CPosition *GT009;
CPosition *GT044;
CPosition *GU002;
CPosition *GU004;
CPosition *GU009;
CPosition *GU069;
CPosition *GUKDO;
CPosition *GUKSU;
CPosition *GUMSA;
CPosition *GUKOB;
CPosition *UNTOM;
CPosition *KALIN;
CPosition *UNVET;
CPosition *SANIB;
CPosition *BORNU;
CPosition *WADIO;
CPosition *TORIA;
CPosition *BUNDA;
CPosition *SCURU;
CPosition *MILOO;
CPosition *GUNKU;
CPosition *GUPLA;
CPosition *HAEGU;
CPosition *HAEUN;
CPosition *HALNA;
CPosition *HALUN;
CPosition *HAMUN;
CPosition *HANAB;
CPosition *HANEE;
CPosition *HD050;
CPosition *HD100;
CPosition *HEDOD;
CPosition *HP121;
CPosition *HUPHO;
CPosition *HWANI;
CPosition *HYEIN;
CPosition *OSNOP;
CPosition *ICHE;
CPosition *ICHG;
CPosition *ICHJ;
CPosition *ICJU;
CPosition *IDAG;
CPosition *IDIVU;
CPosition *IDROL;
CPosition *IDVIT;
CPosition *IGASA;
CPosition *IGDOK;
CPosition *IGMEL;
CPosition *IGPER;
CPosition *IGROD;
CPosition *IJDG;
CPosition *IKADI;
CPosition *IKAPO;
CPosition *IKEDO;
CPosition *IKEKA;
CPosition *IKESI;
CPosition *IKHE;
CPosition *IKMA;
CPosition *IKMO;
CPosition *IKPO;
CPosition *IKUMU;
CPosition *IKUZ;
CPosition *IMAN;
CPosition *IMDG;
CPosition *IMDH;
CPosition *IMUN;
CPosition *INLL;
CPosition *INRR;
CPosition *IOFR;
CPosition *INTUT;
CPosition *IPDAS;
CPosition *IPKOL;
CPosition *LILVI;
CPosition *IRFN;
CPosition *IRFS;
CPosition *IRKN;
CPosition *IRKS;
CPosition *ISAKY;
CPosition *ISAM;
CPosition *ISDOV;
CPosition *ISEL;
CPosition *ISHA;
CPosition *ISKP;
CPosition *ISLL;
CPosition *ISOL;
CPosition *ISRIV;
CPosition *ISRR;
CPosition *ISUL;
CPosition *ITAG;
CPosition *ITGL;
CPosition *IUJN;
CPosition *IUJS;
CPosition *IULS;
CPosition *IVPR;
CPosition *IYAN;
CPosition *IYSO;
CPosition *IYSU;
CPosition *IEODO;
CPosition *JADOO;
CPosition *JALDA;
CPosition *JB701;
CPosition *JB702;
CPosition *JB703;
CPosition *JB704;
CPosition *JB705;
CPosition *JB706;
CPosition *JB751;
CPosition *JB752;
CPosition *JB753;
CPosition *JB754;
CPosition *JB755;
CPosition *JB801;
CPosition *JB802;
CPosition *JB803;
CPosition *JB804;
CPosition *JB805;
CPosition *JB806;
CPosition *JB807;
CPosition *JB808;
CPosition *JB809;
CPosition *JB851;
CPosition *JB852;
CPosition *JB853;
CPosition *JB854;
CPosition *JB855;
CPosition *JB856;
CPosition *JB857;
CPosition *JB858;
CPosition *JB859;
CPosition *IPDUT;
CPosition *JENAM;
CPosition *JIKJI;
CPosition *JINRO;
CPosition *JJ221;
CPosition *JJ222;
CPosition *JJ223;
CPosition *JJ224;
CPosition *JJ321;
CPosition *JJ322;
CPosition *JJ323;
CPosition *JJ401;
CPosition *JJ402;
CPosition *JJ403;
CPosition *JJ481;
CPosition *JJ501;
CPosition *JJ502;
CPosition *JJ503;
CPosition *JJ504;
CPosition *JJ581;
CPosition *JJ681;
CPosition *JJ682;
CPosition *JJ683;
CPosition *JJ781;
CPosition *JJ782;
CPosition *JJ783;
CPosition *JONJU;
CPosition *JY401;
CPosition *JY402;
CPosition *JY752;
CPosition *JY801;
CPosition *JY802;
CPosition *JY803;
CPosition *JY804;
CPosition *JY805;
CPosition *JY806;
CPosition *JY851;
CPosition *JY852;
CPosition *JY853;
CPosition *JY854;
CPosition *JY857;
CPosition *JY865;
CPosition *JY866;
CPosition *KABVO;
CPosition *KADIL;
CPosition *KAGOK;
CPosition *KAIFA;
CPosition *KAKPU;
CPosition *KAKRU;
CPosition *KAKSO;
CPosition *KALMA;
CPosition *KALOD;
CPosition *KALUS;
CPosition *KAMIT;
CPosition *KAMSA;
CPosition *KANKA;
CPosition *KARBU;
CPosition *KASKA;
CPosition *KASPU;
CPosition *KC001;
CPosition *KC003;
CPosition *KC066;
CPosition *KC067;
CPosition *KE008;
CPosition *KE019;
CPosition *ESDEM;
CPosition *GE019;
CPosition *KE035;
CPosition *KE044;
CPosition *KEVAP;
CPosition *KEVOX;
CPosition *KICHA;
CPosition *KIDAB;
CPosition *KIDOS;
CPosition *KIXIS;
CPosition *KM401;
CPosition *KM402;
CPosition *KM403;
CPosition *KM404;
CPosition *KM405;
CPosition *KM411;
CPosition *KM412;
CPosition *KM413;
CPosition *KM414;
CPosition *KM501;
CPosition *KM502;
CPosition *KM503;
CPosition *KM504;
CPosition *KM505;
CPosition *KM511;
CPosition *KM601;
CPosition *KM701;
CPosition *KM702;
CPosition *GUMAK;
CPosition *KOTTY;
CPosition *KT018;
CPosition *APOMO;
CPosition *KT033;
CPosition *KUPER;
CPosition *LAPAL;
CPosition *LATUX;
CPosition *LEBUX;
CPosition *LEDIN;
CPosition *LEGAK;
CPosition *LEGUN;
CPosition *LENBI;
CPosition *LESBU;
CPosition *LIMDI;
CPosition *LIMSO;
CPosition *LINTA;
CPosition *LOSNI;
CPosition *LOSTO;
CPosition *LUKKI;
CPosition *LUKLI;
CPosition *LUPAS;
CPosition *MABON;
CPosition *MAEMI;
CPosition *MAKDU;
CPosition *MAKET;
CPosition *MAKKY;
CPosition *MAKSA;
CPosition *MAKUN;
CPosition *MALSO;
CPosition *MANBA;
CPosition *MANGI;
CPosition *MANOL;
CPosition *MARMI;
CPosition *MASTA;
CPosition *MATEN;
CPosition *MATIZ;
CPosition *DOVUR;
CPosition *KABAS;
CPosition *MEDIO;
CPosition *MEESA;
CPosition *MEKIL;
CPosition *MELES;
CPosition *MENIV;
CPosition *MENOL;
CPosition *JISUN;
CPosition *MEXER;
CPosition *MIGOL;
CPosition *MIKES;
CPosition *MOBAK;
CPosition *MONSI;
CPosition *MOXID;
CPosition *MUBIX;
CPosition *MUGAR;
CPosition *MUMUT;
CPosition *MARYO;
CPosition *MUNAN;
CPosition *MUPAS;
CPosition *NAISS;
CPosition *NAKZY;
CPosition *NARAE;
CPosition *NATEK;
CPosition *NEIAN;
CPosition *NIMAL;
CPosition *ESNEG;
CPosition *NIPUT;
CPosition *NIRAT;
CPosition *NISAV;
CPosition *TEPEL;
CPosition *NOBOB;
CPosition *NOBUT;
CPosition *NODUN;
CPosition *NOGON;
CPosition *NOGUB;
CPosition *NULDI;
CPosition *NUTBO;
CPosition *GT020;
CPosition *NONOS;
CPosition *NOORI;
CPosition *NOPEN;
CPosition *NOPIK;
CPosition *ARIMU;
CPosition *NUKBA;
CPosition *NULAR;
CPosition *NUSLO;
CPosition *NY000;
CPosition *NY003;
CPosition *NY004;
CPosition *NY010;
CPosition *NY015;
CPosition *NY031;
CPosition *NY040;
CPosition *NY042;
CPosition *NY049;
CPosition *NY050;
CPosition *NY070;
CPosition *NY090;
CPosition *IGBEM;
CPosition *OKTUL;
CPosition *OLBES;
CPosition *OLBIM;
CPosition *OLKIK;
CPosition *OLLEH;
CPosition *OLMEN;
CPosition *OLMOG;
CPosition *OLMUD;
CPosition *OLNIG;
CPosition *OLTEM;
CPosition *OMKEL;
CPosition *OMKIM;
CPosition *OMOTU;
CPosition *ONAPU;
CPosition *ONATA;
CPosition *OPEDA;
CPosition *OPONO;
CPosition *OSERI;
CPosition *OSIVI;
CPosition *OSPOT;
CPosition *OSROX;
CPosition *OSVOM;
CPosition *OVGEN;
CPosition *OVLIN;
CPosition *OVTUS;
CPosition *OWING;
CPosition *P2;
CPosition *PALDU;
CPosition *PALRI;
CPosition *PALSA;
CPosition *PAMBI;
CPosition *PANSI;
CPosition *PAPLU;
CPosition *PAPTO;
CPosition *PC401;
CPosition *PC621;
CPosition *PC622;
CPosition *PC623;
CPosition *PC624;
CPosition *PC625;
CPosition *PC626;
CPosition *PC628;
CPosition *PC721;
CPosition *PC722;
CPosition *PC723;
CPosition *PC724;
CPosition *PC725;
CPosition *PC726;
CPosition *PC727;
CPosition *PC728;
CPosition *PC735;
CPosition *PC764;
CPosition *PC761;
CPosition *PC762;
CPosition *PC763;
CPosition *PC767;
CPosition *VEKDI;
CPosition *DOKVU;
CPosition *KIBEK;
CPosition *PC682;
CPosition *PC683;
CPosition *PC684;
CPosition *PC685;
CPosition *LIDVO;
CPosition *PC765;
CPosition *PC811;
CPosition *PC813;
CPosition *PC814;
CPosition *PC816;
CPosition *PC832;
CPosition *PC833;
CPosition *PC834;
CPosition *PC841;
CPosition *PC842;
CPosition *PC845;
CPosition *PC846;
CPosition *PC861;
CPosition *PC871;
CPosition *PC872;
CPosition *PC874;
CPosition *PD501;
CPosition *PD502;
CPosition *PD701;
CPosition *PD702;
CPosition *PD703;
CPosition *PD704;
CPosition *PD705;
CPosition *PD706;
CPosition *PD801;
CPosition *PD802;
CPosition *PD803;
CPosition *PD804;
CPosition *PD805;
CPosition *PD806;
CPosition *PD807;
CPosition *PD808;
CPosition *PD811;
CPosition *PD812;
CPosition *PD813;
CPosition *PD814;
CPosition *PE029;
CPosition *PE048;
CPosition *PE054;
CPosition *PEBRI;
CPosition *PEDLO;
CPosition *PEGMI;
CPosition *PEGRO;
CPosition *PH002;
CPosition *PH036;
CPosition *PH037;
CPosition *PIBAK;
CPosition *PIKAR;
CPosition *PILIT;
CPosition *PIMIK;
CPosition *PINAS;
CPosition *PINEV;
CPosition *PIPAN;
CPosition *PK513;
CPosition *PK514;
CPosition *PK521;
CPosition *PK522;
CPosition *PK711;
CPosition *PK712;
CPosition *PK722;
CPosition *PK731;
CPosition *POLEG;
CPosition *POMIM;
CPosition *POMOX;
CPosition *PONIK;
CPosition *PONIL;
CPosition *PORIX;
CPosition *POSAN;
CPosition *POSCO;
CPosition *POSEP;
CPosition *POSOK;
CPosition *POTET;
CPosition *POVEM;
CPosition *POVOR;
CPosition *PQ032;
CPosition *PQ058;
CPosition *PQ070;
CPosition *PQ078;
CPosition *PQ091;
CPosition *PT017;
CPosition *SUNEM;
CPosition *PT029;
CPosition *PT030;
CPosition *PT041;
CPosition *PT042;
CPosition *PT054;
CPosition *PT055;
CPosition *PT062;
CPosition *PT075;
CPosition *PT091;
CPosition *PU025;
CPosition *PU029;
CPosition *PU033;
CPosition *PU044;
CPosition *PU046;
CPosition *PU060;
CPosition *PU063;
CPosition *PU402;
CPosition *PU403;
CPosition *PU501;
CPosition *PU701;
CPosition *PU751;
CPosition *PU752;
CPosition *PU801;
CPosition *PU802;
CPosition *PU803;
CPosition *PU851;
CPosition *PU852;
CPosition *PU853;
CPosition *PUDEN;
CPosition *PUDIM;
CPosition *PUDUB;
CPosition *PY019;
CPosition *PY031;
CPosition *PY036;
CPosition *PY049;
CPosition *PY421;
CPosition *PY422;
CPosition *PY423;
CPosition *PY426;
CPosition *PY431;
CPosition *PY432;
CPosition *PY433;
CPosition *PY434;
CPosition *PY435;
CPosition *PY521;
CPosition *PY531;
CPosition *PY621;
CPosition *PY622;
CPosition *PZ026;
CPosition *PZ030;
CPosition *PZ035;
CPosition *PZ040;
CPosition *PZ049;
CPosition *PZ061;
CPosition *QD040;
CPosition *QD050;
CPosition *QD080;
CPosition *QD090;
CPosition *QD110;
CPosition *QD150;
CPosition *QD160;
CPosition *QG180;
CPosition *QK080;
CPosition *QP079;
CPosition *QP080;
CPosition *QP120;
CPosition *REBIT;
CPosition *RELEX;
CPosition *REMOS;
CPosition *RENEK;
CPosition *RETAG;
CPosition *RILRO;
CPosition *RIMPO;
CPosition *RIMTA;
CPosition *RINBO;
CPosition *RITEK;
CPosition *ROCEE;
CPosition *GUMAM;
CPosition *RUMRI;
CPosition *RUNIT;
CPosition *RUNSA;
CPosition *RUTON;
CPosition *RUVIS;
CPosition *SABET;
CPosition *SABUM;
CPosition *SACUN;
CPosition *SADLI;
CPosition *SAKOS;
CPosition *SAKYU;
CPosition *SALMI;
CPosition *SAMLO;
CPosition *SAMON;
CPosition *SAMUL;
CPosition *SANKO;
CPosition *MEVIM;
CPosition *SANLA;
CPosition *SAPDI;
CPosition *SAPUX;
CPosition *SARAM;
CPosition *SASRI;
CPosition *SEDMO;
CPosition *SEGBO;
CPosition *SEHEE;
CPosition *SELPA;
CPosition *SEPCO;
CPosition *LUVOL;
CPosition *ONUGO;
CPosition *SKOTA;
CPosition *SLOTA;
CPosition *SOCHA;
CPosition *SOKGE;
CPosition *SOMSA;
CPosition *SONDO;
CPosition *SOONA;
CPosition *SOONI;
CPosition *SOORO;
CPosition *BEVSI;
CPosition *SOSDO;
CPosition *STOUT;
CPosition *SUBTA;
CPosition *SUBUK;
CPosition *SUPOM;
CPosition *SUPUL;
CPosition *SURAK;
CPosition *SURAX;
CPosition *SURSO;
CPosition *TAMNA;
CPosition *TASUR;
CPosition *TAXUK;
CPosition *TD040;
CPosition *TD050;
CPosition *TD100;
CPosition *TD120;
CPosition *TD130;
CPosition *TD180;
CPosition *TD200;
CPosition *TEBEX;
CPosition *TEDAN;
CPosition *TENAS;
CPosition *TENUL;
CPosition *TERNI;
CPosition *TESIK;
CPosition *TESIM;
CPosition *TEWOO;
CPosition *TH501;
CPosition *TH503;
CPosition *TH505;
CPosition *TH701;
CPosition *TH702;
CPosition *TH801;
CPosition *TH802;
CPosition *TH803;
CPosition *TH804;
CPosition *TH805;
CPosition *TH806;
CPosition *TH901;
CPosition *TH902;
CPosition *TH903;
CPosition *TH904;
CPosition *TH905;
CPosition *TH906;
CPosition *PIGEL;
CPosition *TIQUE;
CPosition *TK130;
CPosition *TL001;
CPosition *TL002;
CPosition *TL003;
CPosition *TL004;
CPosition *TL011;
CPosition *TL012;
CPosition *TL013;
CPosition *TL024;
CPosition *TL025;
CPosition *TL026;
CPosition *TL034;
CPosition *TL035;
CPosition *TL041;
CPosition *TL043;
CPosition *TL051;
CPosition *TL053;
CPosition *TL121;
CPosition *TL222;
CPosition *TL223;
CPosition *TL131;
CPosition *TL232;
CPosition *TL233;
CPosition *TODAL;
CPosition *TOKIN;
CPosition *TOLIS;
CPosition *TONIN;
CPosition *TONIX;
CPosition *TOPAX;
CPosition *TOREN;
CPosition *TORUS;
CPosition *TOSAN;
CPosition *TP080;
CPosition *TP120;
CPosition *TU521;
CPosition *TU743;
CPosition *TU746;
CPosition *TU761;
CPosition *TU762;
CPosition *TU763;
CPosition *TU766;
CPosition *TURTU;
CPosition *TUTAE;
CPosition *TUVRO;
CPosition *TN311;
CPosition *TN131;
CPosition *TN312;
CPosition *TN132;
CPosition *TN451;
CPosition *TN652;
CPosition *TN653;
CPosition *TN401;
CPosition *TN403;
CPosition *TN603;
CPosition *TN633;
CPosition *UD050;
CPosition *TN503;
CPosition *UD060;
CPosition *TN601;
CPosition *TN602;
CPosition *TN701;
CPosition *TN702;
CPosition *UD080;
CPosition *UD100;
CPosition *UPDET;
CPosition *UGOVI;
CPosition *UG100;
CPosition *UG130;
CPosition *UKBAT;
CPosition *ULSUK;
CPosition *UMNAE;
CPosition *UP050;
CPosition *UP059;
CPosition *UP060;
CPosition *UP100;
CPosition *UPGOS;
CPosition *UPLAP;
CPosition *UPMAN;
CPosition *UPREX;
CPosition *UPROR;
CPosition *UPSOM;
CPosition *UPTAD;
CPosition *UPTIL;
CPosition *VASLI;
CPosition *VASVA;
CPosition *VATIS;
CPosition *VELKI;
CPosition *VEMUM;
CPosition *VIPIR;
CPosition *VISET;
CPosition *WAROB;
CPosition *WASAN;
CPosition *WAYBI;
CPosition *WINTE;
CPosition *WONAP;
CPosition *WONKO;
CPosition *WWOLF;
CPosition *WYZRD;
CPosition *XEMIX;
CPosition *YAWAN;
CPosition *YD020;
CPosition *YD040;
CPosition *YD070;
CPosition *YD100;
CPosition *YD130;
CPosition *YD160;
CPosition *YD190;
CPosition *YEJEE;
CPosition *YEOJU;
CPosition *YEONA;
CPosition *YG160;
CPosition *YK130;
CPosition *YK170;
CPosition *YK210;
CPosition *YOMJU;
CPosition *YP080;
CPosition *YUMIN;
CPosition *ZD080;
CPosition *ZD100;
CPosition *ZD119;
CPosition *ZD120;
CPosition *ZENZA;
CPosition *ZG130;
CPosition *ZIKKO;
CPosition *ZUDUX;

void InitializeFixes() {
    JOOKA = &fix_list[0];
    fix_list[0].m_Latitude = 37.56912222222223;
    fix_list[0].m_Longitude = 128.22924166666667;

    ANOTI = &fix_list[1];
    fix_list[1].m_Latitude = 37.628572222222225;
    fix_list[1].m_Longitude = 128.0789611111111;

    VEMPU = &fix_list[2];
    fix_list[2].m_Latitude = 37.69777777777777;
    fix_list[2].m_Longitude = 127.88333333333333;

    CASTO = &fix_list[3];
    fix_list[3].m_Latitude = 37.568219444444445;
    fix_list[3].m_Longitude = 128.04135277777777;

    OLTOV = &fix_list[4];
    fix_list[4].m_Latitude = 37.53803055555555;
    fix_list[4].m_Longitude = 128.02255000000002;

    POLLU = &fix_list[5];
    fix_list[5].m_Latitude = 37.49376111111111;
    fix_list[5].m_Longitude = 127.995025;

    ANKEG = &fix_list[6];
    fix_list[6].m_Latitude = 37.46854166666667;
    fix_list[6].m_Longitude = 127.97935833333334;

    VEMTI = &fix_list[7];
    fix_list[7].m_Latitude = 37.66563055555555;
    fix_list[7].m_Longitude = 127.98491388888888;

    ENDEX = &fix_list[8];
    fix_list[8].m_Latitude = 37.284225;
    fix_list[8].m_Longitude = 127.74878055555556;

    IKOSU = &fix_list[9];
    fix_list[9].m_Latitude = 37.247347222222224;
    fix_list[9].m_Longitude = 127.84245555555555;

    DOXEL = &fix_list[10];
    fix_list[10].m_Latitude = 37.31764166666667;
    fix_list[10].m_Longitude = 127.88587222222223;

    KORHA = &fix_list[11];
    fix_list[11].m_Latitude = 37.337744444444446;
    fix_list[11].m_Longitude = 127.89829722222223;

    OLSAX = &fix_list[12];
    fix_list[12].m_Latitude = 37.38203333333333;
    fix_list[12].m_Longitude = 127.92571111111111;

    DUBAL = &fix_list[13];
    fix_list[13].m_Latitude = 37.407488888888885;
    fix_list[13].m_Longitude = 127.94148055555556;

    OLGOD = &fix_list[14];
    fix_list[14].m_Latitude = 37.21039444444445;
    fix_list[14].m_Longitude = 127.93604166666667;

    ORINU = &fix_list[15];
    fix_list[15].m_Latitude = 37.237499722222225;
    fix_list[15].m_Longitude = 127.74555583333333;

    AD020 = &fix_list[16];
    fix_list[16].m_Latitude = 37.57919444444445;
    fix_list[16].m_Longitude = 126.35527777777777;

    AD050 = &fix_list[17];
    fix_list[17].m_Latitude = 37.579638888888894;
    fix_list[17].m_Longitude = 126.2085;

    ADGES = &fix_list[18];
    fix_list[18].m_Latitude = 34.634166666666665;
    fix_list[18].m_Longitude = 127.58722222222222;

    AGBIS = &fix_list[19];
    fix_list[19].m_Latitude = 42.78915833333333;
    fix_list[19].m_Longitude = 131.44084722222223;

    AGSUS = &fix_list[20];
    fix_list[20].m_Latitude = 36.763286944444445;
    fix_list[20].m_Longitude = 130.69055111111112;

    AGUTI = &fix_list[21];
    fix_list[21].m_Latitude = 35.028166666666664;
    fix_list[21].m_Longitude = 127.526;

    AKARA = &fix_list[22];
    fix_list[22].m_Latitude = 31.499959444444446;
    fix_list[22].m_Longitude = 123.49997861111112;

    AKBIN = &fix_list[23];
    fix_list[23].m_Latitude = 33.522638888888885;
    fix_list[23].m_Longitude = 126.2486938888889;

    AKEVI = &fix_list[24];
    fix_list[24].m_Latitude = 34.974722222222226;
    fix_list[24].m_Longitude = 128.9633333333333;

    AKIAS = &fix_list[25];
    fix_list[25].m_Latitude = 38.617195;
    fix_list[25].m_Longitude = 136.90104694444446;

    AKPET = &fix_list[26];
    fix_list[26].m_Latitude = 34.97008277777778;
    fix_list[26].m_Longitude = 127.91583583333333;

    AKUBO = &fix_list[27];
    fix_list[27].m_Latitude = 35.12697222222222;
    fix_list[27].m_Longitude = 127.90633333333334;

    AKLOG = &fix_list[28];
    fix_list[28].m_Latitude = 35.03408333333333;
    fix_list[28].m_Longitude = 127.97594444444445;

    PS241 = &fix_list[29];
    fix_list[29].m_Latitude = 35.14630555555556;
    fix_list[29].m_Longitude = 127.877;

    PS242 = &fix_list[30];
    fix_list[30].m_Latitude = 35.226333333333336;
    fix_list[30].m_Longitude = 127.98152777777779;

    PS243 = &fix_list[31];
    fix_list[31].m_Latitude = 34.91975;
    fix_list[31].m_Longitude = 128.0711388888889;

    PS244 = &fix_list[32];
    fix_list[32].m_Latitude = 35.23277777777778;
    fix_list[32].m_Longitude = 128.3995;

    PS151 = &fix_list[33];
    fix_list[33].m_Latitude = 34.74944444444444;
    fix_list[33].m_Longitude = 128.13680555555555;

    PS152 = &fix_list[34];
    fix_list[34].m_Latitude = 34.58938888888889;
    fix_list[34].m_Longitude = 128.02502777777778;

    PS061 = &fix_list[35];
    fix_list[35].m_Latitude = 35.27283333333333;
    fix_list[35].m_Longitude = 128.05758333333335;

    PS062 = &fix_list[36];
    fix_list[36].m_Latitude = 35.20538888888889;
    fix_list[36].m_Longitude = 127.83655555555555;

    PS603 = &fix_list[37];
    fix_list[37].m_Latitude = 34.96291666666667;
    fix_list[37].m_Longitude = 128.14919444444445;

    PS604 = &fix_list[38];
    fix_list[38].m_Latitude = 34.620777777777775;
    fix_list[38].m_Longitude = 127.8543611111111;

    PS421 = &fix_list[39];
    fix_list[39].m_Latitude = 35.06561111111111;
    fix_list[39].m_Longitude = 128.0271388888889;

    PS422 = &fix_list[40];
    fix_list[40].m_Latitude = 35.163805555555555;
    fix_list[40].m_Longitude = 128.49780555555554;

    PS423 = &fix_list[41];
    fix_list[41].m_Latitude = 34.60733333333334;
    fix_list[41].m_Longitude = 127.90333333333334;

    PS424 = &fix_list[42];
    fix_list[42].m_Latitude = 34.82741666666667;
    fix_list[42].m_Longitude = 127.97275;

    PS426 = &fix_list[43];
    fix_list[43].m_Latitude = 35.39091666666667;
    fix_list[43].m_Longitude = 128.20452777777777;

    PS482 = &fix_list[44];
    fix_list[44].m_Latitude = 35.129555555555555;
    fix_list[44].m_Longitude = 128.14105555555554;

    PS581 = &fix_list[45];
    fix_list[45].m_Latitude = 35.16236111111111;
    fix_list[45].m_Longitude = 128.36705555555557;

    PS582 = &fix_list[46];
    fix_list[46].m_Latitude = 35.288777777777774;
    fix_list[46].m_Longitude = 128.26211111111112;

    PS583 = &fix_list[47];
    fix_list[47].m_Latitude = 35.12861111111111;
    fix_list[47].m_Longitude = 128.14383333333333;

    PS584 = &fix_list[48];
    fix_list[48].m_Latitude = 35.17586111111111;
    fix_list[48].m_Longitude = 128.22358333333332;

    PS681 = &fix_list[49];
    fix_list[49].m_Latitude = 34.980555555555554;
    fix_list[49].m_Longitude = 127.76194444444444;

    PS682 = &fix_list[50];
    fix_list[50].m_Latitude = 34.88883333333333;
    fix_list[50].m_Longitude = 127.83866666666667;

    PS683 = &fix_list[51];
    fix_list[51].m_Latitude = 35.04094444444444;
    fix_list[51].m_Longitude = 127.98369444444444;

    PS684 = &fix_list[52];
    fix_list[52].m_Latitude = 34.99261111111111;
    fix_list[52].m_Longitude = 127.89819444444446;

    PS781 = &fix_list[53];
    fix_list[53].m_Latitude = 34.99172222222222;
    fix_list[53].m_Longitude = 127.90097222222222;

    PS782 = &fix_list[54];
    fix_list[54].m_Latitude = 35.04002777777777;
    fix_list[54].m_Longitude = 127.98647222222222;

    PS791 = &fix_list[55];
    fix_list[55].m_Latitude = 35.17488888888889;
    fix_list[55].m_Longitude = 128.22633333333334;

    PABKO = &fix_list[56];
    fix_list[56].m_Latitude = 34.94419444444444;
    fix_list[56].m_Longitude = 127.81708333333333;

    GOLOG = &fix_list[57];
    fix_list[57].m_Latitude = 35.00447222222222;
    fix_list[57].m_Longitude = 127.92351388888889;

    GUTVA = &fix_list[58];
    fix_list[58].m_Latitude = 34.94552777777778;
    fix_list[58].m_Longitude = 127.81508333333333;

    GIVOD = &fix_list[59];
    fix_list[59].m_Latitude = 35.00530555555556;
    fix_list[59].m_Longitude = 127.92063888888889;

    BUVPU = &fix_list[60];
    fix_list[60].m_Latitude = 35.224722222222226;
    fix_list[60].m_Longitude = 128.31533333333334;

    IGULO = &fix_list[61];
    fix_list[61].m_Latitude = 35.156055555555554;
    fix_list[61].m_Longitude = 128.19272222222222;

    BUPGU = &fix_list[62];
    fix_list[62].m_Latitude = 35.15702777777778;
    fix_list[62].m_Longitude = 128.18998611111112;

    AGTEG = &fix_list[63];
    fix_list[63].m_Latitude = 35.226444444444446;
    fix_list[63].m_Longitude = 128.31391666666667;

    BOTRU = &fix_list[64];
    fix_list[64].m_Latitude = 35.028166666666664;
    fix_list[64].m_Longitude = 128.2665;

    VONDU = &fix_list[65];
    fix_list[65].m_Latitude = 35.14333333333333;
    fix_list[65].m_Longitude = 128.16558333333333;

    SOLYI = &fix_list[66];
    fix_list[66].m_Latitude = 35.03594444444444;
    fix_list[66].m_Longitude = 127.73933333333333;

    VIBOR = &fix_list[67];
    fix_list[67].m_Latitude = 34.85169444444445;
    fix_list[67].m_Longitude = 127.89341666666667;

    NOBOP = &fix_list[68];
    fix_list[68].m_Latitude = 35.31122222222222;
    fix_list[68].m_Longitude = 128.17425;

    RUPIB = &fix_list[69];
    fix_list[69].m_Latitude = 34.93411111111111;
    fix_list[69].m_Longitude = 127.79458333333334;

    MAMVI = &fix_list[70];
    fix_list[70].m_Latitude = 34.977444444444444;
    fix_list[70].m_Longitude = 128.19619444444444;

    AURIO = &fix_list[71];
    fix_list[71].m_Latitude = 34.988194444444446;
    fix_list[71].m_Longitude = 127.89016666666667;

    OLNOB = &fix_list[72];
    fix_list[72].m_Latitude = 35.0025;
    fix_list[72].m_Longitude = 127.91833333333334;

    FOKAN = &fix_list[73];
    fix_list[73].m_Latitude = 35.04108333333333;
    fix_list[73].m_Longitude = 127.98386111111111;

    GAFOA = &fix_list[74];
    fix_list[74].m_Latitude = 35.07880555555556;
    fix_list[74].m_Longitude = 128.05086111111112;

    AKPON = &fix_list[75];
    fix_list[75].m_Latitude = 33.78055555555555;
    fix_list[75].m_Longitude = 127.33138888888888;

    ALDON = &fix_list[76];
    fix_list[76].m_Latitude = 36.946194444444444;
    fix_list[76].m_Longitude = 129.58972222222224;

    AVMET = &fix_list[77];
    fix_list[77].m_Latitude = 34.452111111111115;
    fix_list[77].m_Longitude = 127.77483333333333;

    ANBOG = &fix_list[78];
    fix_list[78].m_Latitude = 37.58738888888889;
    fix_list[78].m_Longitude = 126.34219444444444;

    ANJAY = &fix_list[79];
    fix_list[79].m_Latitude = 34.76186111111111;
    fix_list[79].m_Longitude = 127.65658333333334;

    ANKIB = &fix_list[80];
    fix_list[80].m_Latitude = 36.650749999999995;
    fix_list[80].m_Longitude = 127.39127777777779;

    ANKOG = &fix_list[81];
    fix_list[81].m_Latitude = 41.72222222222222;
    fix_list[81].m_Longitude = 130.27833333333334;

    ANKUS = &fix_list[82];
    fix_list[82].m_Latitude = 35.125;
    fix_list[82].m_Longitude = 128.7711111111111;

    ANROD = &fix_list[83];
    fix_list[83].m_Latitude = 34.632777777777775;
    fix_list[83].m_Longitude = 128.49777777777777;

    ANSIM = &fix_list[84];
    fix_list[84].m_Latitude = 37.389695833333334;
    fix_list[84].m_Longitude = 124.82524388888889;

    ANUBA = &fix_list[85];
    fix_list[85].m_Latitude = 35.12433277777778;
    fix_list[85].m_Longitude = 127.58716638888889;

    AP140 = &fix_list[86];
    fix_list[86].m_Latitude = 37.404694444444445;
    fix_list[86].m_Longitude = 125.75594444444444;

    APARU = &fix_list[87];
    fix_list[87].m_Latitude = 35.419689999999996;
    fix_list[87].m_Longitude = 129.1644425;

    APDOP = &fix_list[88];
    fix_list[88].m_Latitude = 35.92372222222222;
    fix_list[88].m_Longitude = 126.61113888888889;

    APITO = &fix_list[89];
    fix_list[89].m_Latitude = 29.589333333333332;
    fix_list[89].m_Longitude = 123.99066638888888;

    OLVAR = &fix_list[90];
    fix_list[90].m_Latitude = 35.96202777777778;
    fix_list[90].m_Longitude = 128.53716666666668;

    ARECO = &fix_list[91];
    fix_list[91].m_Latitude = 35.239472222222226;
    fix_list[91].m_Longitude = 128.78308333333334;

    ASORA = &fix_list[92];
    fix_list[92].m_Latitude = 36.711222222222226;
    fix_list[92].m_Longitude = 127.47211111111112;

    ATASO = &fix_list[93];
    fix_list[93].m_Latitude = 35.89066583333333;
    fix_list[93].m_Longitude = 126.94283333333334;

    ATIMO = &fix_list[94];
    fix_list[94].m_Latitude = 33.39791666666667;
    fix_list[94].m_Longitude = 126.73088888888888;

    ATINA = &fix_list[95];
    fix_list[95].m_Latitude = 33.72601111111111;
    fix_list[95].m_Longitude = 127.08353444444444;

    ATKON = &fix_list[96];
    fix_list[96].m_Latitude = 37.666555555555554;
    fix_list[96].m_Longitude = 126.30644444444444;

    ATLAX = &fix_list[97];
    fix_list[97].m_Latitude = 35.36361111111111;
    fix_list[97].m_Longitude = 129.075;

    AVNIS = &fix_list[98];
    fix_list[98].m_Latitude = 34.89411111111111;
    fix_list[98].m_Longitude = 126.38355555555556;

    AYEON = &fix_list[99];
    fix_list[99].m_Latitude = 35.152832777777775;
    fix_list[99].m_Longitude = 126.20891694444445;

    AZUKI = &fix_list[100];
    fix_list[100].m_Latitude = 32.401916944444444;
    fix_list[100].m_Longitude = 127.581;

    BAHDA = &fix_list[101];
    fix_list[101].m_Latitude = 34.89211777777778;
    fix_list[101].m_Longitude = 128.95765083333333;

    BAKJO = &fix_list[102];
    fix_list[102].m_Latitude = 36.55558333333333;
    fix_list[102].m_Longitude = 127.23875;

    BANYA = &fix_list[103];
    fix_list[103].m_Latitude = 36.669309722222216;
    fix_list[103].m_Longitude = 129.67602944444442;

    BASEM = &fix_list[104];
    fix_list[104].m_Latitude = 36.84372194444445;
    fix_list[104].m_Longitude = 127.95269444444445;

    BATAP = &fix_list[105];
    fix_list[105].m_Latitude = 37.34852777777778;
    fix_list[105].m_Longitude = 126.55466666666666;

    BEDES = &fix_list[106];
    fix_list[106].m_Latitude = 36.15138833333333;
    fix_list[106].m_Longitude = 126.81222194444445;

    BEDOM = &fix_list[107];
    fix_list[107].m_Latitude = 35.42027777777778;
    fix_list[107].m_Longitude = 129.29833333333332;

    BEETL = &fix_list[108];
    fix_list[108].m_Latitude = 34.26240888888889;
    fix_list[108].m_Longitude = 129.82922944444445;

    BELTU = &fix_list[109];
    fix_list[109].m_Latitude = 37.20505527777778;
    fix_list[109].m_Longitude = 125.79972166666667;

    BEMGA = &fix_list[110];
    fix_list[110].m_Latitude = 35.17052777777778;
    fix_list[110].m_Longitude = 126.38238833333332;

    BEPKO = &fix_list[111];
    fix_list[111].m_Latitude = 33.65277777777778;
    fix_list[111].m_Longitude = 126.92055555555557;

    BEZEE = &fix_list[112];
    fix_list[112].m_Latitude = 35.88305555555556;
    fix_list[112].m_Longitude = 126.62080555555555;

    BIDBA = &fix_list[113];
    fix_list[113].m_Latitude = 37.34258277777778;
    fix_list[113].m_Longitude = 127.32069388888888;

    BIDRI = &fix_list[114];
    fix_list[114].m_Latitude = 36.33527777777778;
    fix_list[114].m_Longitude = 124.41472222222222;

    OPIBA = &fix_list[115];
    fix_list[115].m_Latitude = 35.35380555555556;
    fix_list[115].m_Longitude = 126.97005555555556;

    BIGOB = &fix_list[116];
    fix_list[116].m_Latitude = 36.72372166666667;
    fix_list[116].m_Longitude = 128.16444444444446;

    BIGTU = &fix_list[117];
    fix_list[117].m_Latitude = 33.15841666666667;
    fix_list[117].m_Longitude = 126.71286111111111;

    BIKLA = &fix_list[118];
    fix_list[118].m_Latitude = 35.18501083333333;
    fix_list[118].m_Longitude = 128.3402438888889;

    BIKSI = &fix_list[119];
    fix_list[119].m_Latitude = 37.675416388888884;
    fix_list[119].m_Longitude = 128.58447166666667;

    BILUM = &fix_list[120];
    fix_list[120].m_Latitude = 33.77027777777778;
    fix_list[120].m_Longitude = 127.0775;

    BINIL = &fix_list[121];
    fix_list[121].m_Latitude = 37.39694388888889;
    fix_list[121].m_Longitude = 125.23305527777778;

    BINJO = &fix_list[122];
    fix_list[122].m_Latitude = 35.69541666666667;
    fix_list[122].m_Longitude = 129.3202222222222;

    BINOR = &fix_list[123];
    fix_list[123].m_Latitude = 35;
    fix_list[123].m_Longitude = 121.02166694444445;

    BIRIN = &fix_list[124];
    fix_list[124].m_Latitude = 37.24391666666667;
    fix_list[124].m_Longitude = 126.6528888888889;

    BIROB = &fix_list[125];
    fix_list[125].m_Latitude = 38.97242888888889;
    fix_list[125].m_Longitude = 131.00221083333332;

    BIROM = &fix_list[126];
    fix_list[126].m_Latitude = 33.79275;
    fix_list[126].m_Longitude = 126.38605555555556;

    BITIM = &fix_list[127];
    fix_list[127].m_Latitude = 37.68;
    fix_list[127].m_Longitude = 126.41002777777778;

    BITUX = &fix_list[128];
    fix_list[128].m_Latitude = 36.27863027777778;
    fix_list[128].m_Longitude = 128.0286861111111;

    BLAZZ = &fix_list[129];
    fix_list[129].m_Latitude = 36.15658333333333;
    fix_list[129].m_Longitude = 126.55552777777777;

    BOBIB = &fix_list[130];
    fix_list[130].m_Latitude = 37.092111111111116;
    fix_list[130].m_Longitude = 127.06644444444444;

    BODEK = &fix_list[131];
    fix_list[131].m_Latitude = 37.377027777777776;
    fix_list[131].m_Longitude = 126.49497222222222;

    BODOK = &fix_list[132];
    fix_list[132].m_Latitude = 39.48416666666667;
    fix_list[132].m_Longitude = 125.42972222222222;

    BODOL = &fix_list[133];
    fix_list[133].m_Latitude = 37.18944444444444;
    fix_list[133].m_Longitude = 124.83166638888889;

    BOGAN = &fix_list[134];
    fix_list[134].m_Latitude = 37.21107166666667;
    fix_list[134].m_Longitude = 126.47690333333334;

    BOLUT = &fix_list[135];
    fix_list[135].m_Latitude = 28.772777777777776;
    fix_list[135].m_Longitude = 124.70333333333333;

    BONSO = &fix_list[136];
    fix_list[136].m_Latitude = 30.477777777777778;
    fix_list[136].m_Longitude = 125.14749944444445;

    BOPKI = &fix_list[137];
    fix_list[137].m_Latitude = 36.908833333333334;
    fix_list[137].m_Longitude = 126.77502777777778;

    BOPTA = &fix_list[138];
    fix_list[138].m_Latitude = 36.73511055555556;
    fix_list[138].m_Longitude = 126.61622194444443;

    BOREV = &fix_list[139];
    fix_list[139].m_Latitude = 35.669666666666664;
    fix_list[139].m_Longitude = 126.69594444444445;

    BOSPI = &fix_list[140];
    fix_list[140].m_Latitude = 34.97533333333334;
    fix_list[140].m_Longitude = 128.9655833333333;

    BOXOL = &fix_list[141];
    fix_list[141].m_Latitude = 35.74202777777778;
    fix_list[141].m_Longitude = 126.65425;

    OPASI = &fix_list[142];
    fix_list[142].m_Latitude = 34.898472222222225;
    fix_list[142].m_Longitude = 126.6486388888889;

    BUGYO = &fix_list[143];
    fix_list[143].m_Latitude = 34.87388888888889;
    fix_list[143].m_Longitude = 127.45805555555556;

    BUKIL = &fix_list[144];
    fix_list[144].m_Latitude = 36.80645277777778;
    fix_list[144].m_Longitude = 127.6427;

    BULGA = &fix_list[145];
    fix_list[145].m_Latitude = 35.93583333333333;
    fix_list[145].m_Longitude = 129.82333333333332;

    IDEVA = &fix_list[146];
    fix_list[146].m_Latitude = 35.763222222222225;
    fix_list[146].m_Longitude = 128.89575;

    BULTI = &fix_list[147];
    fix_list[147].m_Latitude = 36.722861111111115;
    fix_list[147].m_Longitude = 126.82491666666667;

    BUMEP = &fix_list[148];
    fix_list[148].m_Latitude = 41.897213888888885;
    fix_list[148].m_Longitude = 131.21528888888886;

    BUMSI = &fix_list[149];
    fix_list[149].m_Latitude = 37.252833333333335;
    fix_list[149].m_Longitude = 127.16933333333334;

    BURIM = &fix_list[150];
    fix_list[150].m_Latitude = 34.99786111111111;
    fix_list[150].m_Longitude = 128.94669444444446;

    BUSKO = &fix_list[151];
    fix_list[151].m_Latitude = 37.67583305555555;
    fix_list[151].m_Longitude = 130.26944444444445;

    CAMAS = &fix_list[152];
    fix_list[152].m_Latitude = 32.72253583333333;
    fix_list[152].m_Longitude = 128.26247777777778;

    CAVOI = &fix_list[153];
    fix_list[153].m_Latitude = 37.53388888888889;
    fix_list[153].m_Longitude = 126.56027777777777;

    CD120 = &fix_list[154];
    fix_list[154].m_Latitude = 37.12438888888889;
    fix_list[154].m_Longitude = 126.62533333333333;

    CELCA = &fix_list[155];
    fix_list[155].m_Latitude = 37.48852;
    fix_list[155].m_Longitude = 136.10111694444444;

    CG050 = &fix_list[156];
    fix_list[156].m_Latitude = 37.37177777777778;
    fix_list[156].m_Longitude = 126.58527777777778;

    CG100 = &fix_list[157];
    fix_list[157].m_Latitude = 37.27119444444445;
    fix_list[157].m_Longitude = 126.62883333333333;

    CG101 = &fix_list[158];
    fix_list[158].m_Latitude = 37.28525;
    fix_list[158].m_Longitude = 126.88952777777779;

    CG130 = &fix_list[159];
    fix_list[159].m_Latitude = 37.16825;
    fix_list[159].m_Longitude = 126.9786111111111;

    CG200 = &fix_list[160];
    fix_list[160].m_Latitude = 36.92477777777778;
    fix_list[160].m_Longitude = 127.16211111111112;

    CHANO = &fix_list[161];
    fix_list[161].m_Latitude = 35.104105833333335;
    fix_list[161].m_Longitude = 128.09579194444444;

    CHUJA = &fix_list[162];
    fix_list[162].m_Latitude = 33.99647138888889;
    fix_list[162].m_Longitude = 126.58338888888889;

    CIKRA = &fix_list[163];
    fix_list[163].m_Latitude = 35.80083333333333;
    fix_list[163].m_Longitude = 126.67075;

    CK099 = &fix_list[164];
    fix_list[164].m_Latitude = 37.339222222222226;
    fix_list[164].m_Longitude = 127.24777777777778;

    CK100 = &fix_list[165];
    fix_list[165].m_Latitude = 37.306305555555554;
    fix_list[165].m_Longitude = 127.1226111111111;

    CONAR = &fix_list[166];
    fix_list[166].m_Latitude = 39.36472222222223;
    fix_list[166].m_Longitude = 127.21277777777777;

    CP101 = &fix_list[167];
    fix_list[167].m_Latitude = 37.37177777777778;
    fix_list[167].m_Longitude = 126.58527777777778;

    ATNER = &fix_list[168];
    fix_list[168].m_Latitude = 37.104416666666665;
    fix_list[168].m_Longitude = 126.31458333333333;

    ANPEM = &fix_list[169];
    fix_list[169].m_Latitude = 37.62883333333333;
    fix_list[169].m_Longitude = 126.63016666666665;

    ASIDI = &fix_list[170];
    fix_list[170].m_Latitude = 37.67019444444444;
    fix_list[170].m_Longitude = 126.44736111111112;

    EMSOS = &fix_list[171];
    fix_list[171].m_Latitude = 37.26777777777777;
    fix_list[171].m_Longitude = 126.26183333333333;

    EXUTO = &fix_list[172];
    fix_list[172].m_Latitude = 36.88572222222222;
    fix_list[172].m_Longitude = 126.62472222222222;

    LAPOP = &fix_list[173];
    fix_list[173].m_Latitude = 37.09355555555556;
    fix_list[173].m_Longitude = 126.1213611111111;

    LEGOP = &fix_list[174];
    fix_list[174].m_Latitude = 36.98752777777778;
    fix_list[174].m_Longitude = 126.56127777777778;

    MABLO = &fix_list[175];
    fix_list[175].m_Latitude = 37.43863888888889;
    fix_list[175].m_Longitude = 126.582;

    NOKEB = &fix_list[176];
    fix_list[176].m_Latitude = 37.21338888888889;
    fix_list[176].m_Longitude = 126.31022222222222;

    UDIDA = &fix_list[177];
    fix_list[177].m_Latitude = 37.028999999999996;
    fix_list[177].m_Longitude = 126.62305555555555;

    VIMER = &fix_list[178];
    fix_list[178].m_Latitude = 36.98411111111111;
    fix_list[178].m_Longitude = 126.62358333333333;

    DABIK = &fix_list[179];
    fix_list[179].m_Latitude = 36.29527777777778;
    fix_list[179].m_Longitude = 130.1952777777778;

    DAEBO = &fix_list[180];
    fix_list[180].m_Latitude = 36.141668055555556;
    fix_list[180].m_Longitude = 129.5290177777778;

    VADRO = &fix_list[181];
    fix_list[181].m_Latitude = 34.89761111111111;
    fix_list[181].m_Longitude = 126.65047222222223;

    DAKPI = &fix_list[182];
    fix_list[182].m_Latitude = 33.40325;
    fix_list[182].m_Longitude = 125.88863888888889;

    DALKA = &fix_list[183];
    fix_list[183].m_Latitude = 37.29322222222222;
    fix_list[183].m_Longitude = 126.57494444444444;

    DALPO = &fix_list[184];
    fix_list[184].m_Latitude = 36.97638888888889;
    fix_list[184].m_Longitude = 124.41472222222222;

    DALSU = &fix_list[185];
    fix_list[185].m_Latitude = 35.1252775;
    fix_list[185].m_Longitude = 126.70166666666667;

    VETUP = &fix_list[186];
    fix_list[186].m_Latitude = 36.117416666666664;
    fix_list[186].m_Longitude = 128.3392777777778;

    DANPA = &fix_list[187];
    fix_list[187].m_Latitude = 35.509999722222226;
    fix_list[187].m_Longitude = 124.41472138888889;

    DANTI = &fix_list[188];
    fix_list[188].m_Latitude = 37.30166666666666;
    fix_list[188].m_Longitude = 124.65805555555556;

    DC031 = &fix_list[189];
    fix_list[189].m_Latitude = 37.61233333333333;
    fix_list[189].m_Longitude = 126.49655555555556;

    DC032 = &fix_list[190];
    fix_list[190].m_Latitude = 37.55647222222222;
    fix_list[190].m_Longitude = 126.57441666666666;

    DC035 = &fix_list[191];
    fix_list[191].m_Latitude = 37.55033333333333;
    fix_list[191].m_Longitude = 126.42641666666667;

    DC036 = &fix_list[192];
    fix_list[192].m_Latitude = 37.4945;
    fix_list[192].m_Longitude = 126.50427777777777;

    DC037 = &fix_list[193];
    fix_list[193].m_Latitude = 37.48377777777778;
    fix_list[193].m_Longitude = 126.67547222222223;

    DE030 = &fix_list[194];
    fix_list[194].m_Latitude = 37.040861111111106;
    fix_list[194].m_Longitude = 126.79933333333334;

    DE031 = &fix_list[195];
    fix_list[195].m_Latitude = 37.18644444444444;
    fix_list[195].m_Longitude = 126.98397222222222;

    DH002 = &fix_list[196];
    fix_list[196].m_Latitude = 37.50011111111111;
    fix_list[196].m_Longitude = 126.38550000000001;

    DH017 = &fix_list[197];
    fix_list[197].m_Latitude = 37.51488888888889;
    fix_list[197].m_Longitude = 126.24669444444444;

    DH020 = &fix_list[198];
    fix_list[198].m_Latitude = 37.4605;
    fix_list[198].m_Longitude = 126.29525;

    DH021 = &fix_list[199];
    fix_list[199].m_Latitude = 37.51108333333333;
    fix_list[199].m_Longitude = 126.09572222222222;

    DH022 = &fix_list[200];
    fix_list[200].m_Latitude = 37.45677777777778;
    fix_list[200].m_Longitude = 126.1443888888889;

    DH023 = &fix_list[201];
    fix_list[201].m_Latitude = 37.40611111111111;
    fix_list[201].m_Longitude = 126.34375;

    DH024 = &fix_list[202];
    fix_list[202].m_Latitude = 37.40244444444444;
    fix_list[202].m_Longitude = 126.193;

    DH027 = &fix_list[203];
    fix_list[203].m_Latitude = 37.348083333333335;
    fix_list[203].m_Longitude = 126.24152777777778;

    DH028 = &fix_list[204];
    fix_list[204].m_Latitude = 37.45283333333334;
    fix_list[204].m_Longitude = 125.99355555555556;

    DH029 = &fix_list[205];
    fix_list[205].m_Latitude = 37.398555555555554;
    fix_list[205].m_Longitude = 126.04225;

    DH030 = &fix_list[206];
    fix_list[206].m_Latitude = 37.34427777777778;
    fix_list[206].m_Longitude = 126.09088888888888;

    DH034 = &fix_list[207];
    fix_list[207].m_Latitude = 37.23561111111111;
    fix_list[207].m_Longitude = 126.18797222222223;

    DH047 = &fix_list[208];
    fix_list[208].m_Latitude = 37.038888888888884;
    fix_list[208].m_Longitude = 126.51611111111112;

    DODBI = &fix_list[209];
    fix_list[209].m_Latitude = 35.961222222222226;
    fix_list[209].m_Longitude = 128.5361388888889;

    DOGDI = &fix_list[210];
    fix_list[210].m_Latitude = 35.926721944444445;
    fix_list[210].m_Longitude = 129.20088888888887;

    DOHAE = &fix_list[211];
    fix_list[211].m_Latitude = 39.38333333333333;
    fix_list[211].m_Longitude = 132.43166666666664;

    DOKDO = &fix_list[212];
    fix_list[212].m_Latitude = 37.60475;
    fix_list[212].m_Longitude = 126.55197194444445;

    DOKPA = &fix_list[213];
    fix_list[213].m_Latitude = 35.83766666666667;
    fix_list[213].m_Longitude = 129.53647222222222;

    DOMKO = &fix_list[214];
    fix_list[214].m_Latitude = 32.479999722222225;
    fix_list[214].m_Longitude = 125.98305527777778;

    DONPO = &fix_list[215];
    fix_list[215].m_Latitude = 35.017833333333336;
    fix_list[215].m_Longitude = 123.40116666666667;

    DONVO = &fix_list[216];
    fix_list[216].m_Latitude = 37.566537499999995;
    fix_list[216].m_Longitude = 123.33329583333332;

    DOOBU = &fix_list[217];
    fix_list[217].m_Latitude = 35.51536111111111;
    fix_list[217].m_Longitude = 129.35825;

    PUMEG = &fix_list[218];
    fix_list[218].m_Latitude = 35.225722222222224;
    fix_list[218].m_Longitude = 127.06513888888888;

    DORTI = &fix_list[219];
    fix_list[219].m_Latitude = 35.98941666666667;
    fix_list[219].m_Longitude = 129.56572222222223;

    DOTOL = &fix_list[220];
    fix_list[220].m_Latitude = 34.25427777777778;
    fix_list[220].m_Longitude = 126.61016666666666;

    DOVRA = &fix_list[221];
    fix_list[221].m_Latitude = 35.13272222222222;
    fix_list[221].m_Longitude = 126.52277777777778;

    DOWAN = &fix_list[222];
    fix_list[222].m_Latitude = 35.154471944444445;
    fix_list[222].m_Longitude = 126.554445;

    DRIPS = &fix_list[223];
    fix_list[223].m_Latitude = 35.90893083333333;
    fix_list[223].m_Longitude = 133.8355138888889;

    DRGGN = &fix_list[224];
    fix_list[224].m_Latitude = 37.21758333333334;
    fix_list[224].m_Longitude = 127.41977777777778;

    MUSTG = &fix_list[225];
    fix_list[225].m_Latitude = 36.67894444444444;
    fix_list[225].m_Longitude = 126.98344444444444;

    JULOP = &fix_list[226];
    fix_list[226].m_Latitude = 35.583194444444445;
    fix_list[226].m_Longitude = 126.69277777777778;

    JEWEL = &fix_list[227];
    fix_list[227].m_Latitude = 36.23863888888889;
    fix_list[227].m_Longitude = 126.53683333333333;

    CROUN = &fix_list[228];
    fix_list[228].m_Latitude = 36.84422222222222;
    fix_list[228].m_Longitude = 127.01969444444444;

    JADUB = &fix_list[229];
    fix_list[229].m_Latitude = 37.05683333333333;
    fix_list[229].m_Longitude = 126.61777777777777;

    MONRO = &fix_list[230];
    fix_list[230].m_Latitude = 37.06633333333333;
    fix_list[230].m_Longitude = 126.72119444444445;

    JERMY = &fix_list[231];
    fix_list[231].m_Latitude = 37.081833333333336;
    fix_list[231].m_Longitude = 126.90219444444445;

    CASPR = &fix_list[232];
    fix_list[232].m_Latitude = 37.09030555555556;
    fix_list[232].m_Longitude = 127.00294444444444;

    BEAMR = &fix_list[233];
    fix_list[233].m_Latitude = 37.118138888888886;
    fix_list[233].m_Longitude = 127.34277777777777;

    CELMU = &fix_list[234];
    fix_list[234].m_Latitude = 37.10805555555556;
    fix_list[234].m_Longitude = 127.2183888888889;

    WONLI = &fix_list[235];
    fix_list[235].m_Latitude = 37.10294444444445;
    fix_list[235].m_Longitude = 127.15580555555556;

    ZOBES = &fix_list[236];
    fix_list[236].m_Latitude = 37.094611111111114;
    fix_list[236].m_Longitude = 127.05458333333333;

    AVRIG = &fix_list[237];
    fix_list[237].m_Latitude = 37.125861111111114;
    fix_list[237].m_Longitude = 127.44652777777779;

    STNNN = &fix_list[238];
    fix_list[238].m_Latitude = 37.12325;
    fix_list[238].m_Longitude = 127.44680555555556;

    JINEL = &fix_list[239];
    fix_list[239].m_Latitude = 37.10611111111111;
    fix_list[239].m_Longitude = 127.21858333333334;

    STOWT = &fix_list[240];
    fix_list[240].m_Latitude = 37.10088888888889;
    fix_list[240].m_Longitude = 127.15433333333334;

    VISEN = &fix_list[241];
    fix_list[241].m_Latitude = 37.054361111111106;
    fix_list[241].m_Longitude = 126.61813888888888;

    LAGER = &fix_list[242];
    fix_list[242].m_Latitude = 37.06455555555555;
    fix_list[242].m_Longitude = 126.72222222222223;

    KAYJE = &fix_list[243];
    fix_list[243].m_Latitude = 37.080083333333334;
    fix_list[243].m_Longitude = 126.90430555555557;

    VOKOT = &fix_list[244];
    fix_list[244].m_Latitude = 37.08841666666667;
    fix_list[244].m_Longitude = 127.00344444444444;

    CNNDY = &fix_list[245];
    fix_list[245].m_Latitude = 36.9105;
    fix_list[245].m_Longitude = 127.24347222222222;

    OGBIE = &fix_list[246];
    fix_list[246].m_Latitude = 37.036833333333334;
    fix_list[246].m_Longitude = 126.62141666666666;

    JISOV = &fix_list[247];
    fix_list[247].m_Latitude = 37.051361111111106;
    fix_list[247].m_Longitude = 126.72391666666667;

    BANDT = &fix_list[248];
    fix_list[248].m_Latitude = 37.07725000000001;
    fix_list[248].m_Longitude = 126.90852777777778;

    HUVSU = &fix_list[249];
    fix_list[249].m_Latitude = 37.09180555555556;
    fix_list[249].m_Longitude = 127.01319444444445;

    BRREW = &fix_list[250];
    fix_list[250].m_Latitude = 37.00841666666667;
    fix_list[250].m_Longitude = 126.62930555555555;

    SOJUE = &fix_list[251];
    fix_list[251].m_Latitude = 37.030027777777775;
    fix_list[251].m_Longitude = 126.72980555555556;

    TIMAY = &fix_list[252];
    fix_list[252].m_Latitude = 37.06872222222223;
    fix_list[252].m_Longitude = 126.91086111111112;

    OSIKE = &fix_list[253];
    fix_list[253].m_Latitude = 37.08838888888889;
    fix_list[253].m_Longitude = 127.00347222222223;

    OSCOR = &fix_list[254];
    fix_list[254].m_Latitude = 37.08663888888889;
    fix_list[254].m_Longitude = 127.44816666666667;

    MOKLI = &fix_list[255];
    fix_list[255].m_Latitude = 37.08869444444445;
    fix_list[255].m_Longitude = 127.34405555555556;

    BOBAE = &fix_list[256];
    fix_list[256].m_Latitude = 37.091055555555556;
    fix_list[256].m_Longitude = 127.21911111111112;

    PLSNR = &fix_list[257];
    fix_list[257].m_Latitude = 37.092194444444445;
    fix_list[257].m_Longitude = 127.15663888888889;

    BRRRR = &fix_list[258];
    fix_list[258].m_Latitude = 37.093944444444446;
    fix_list[258].m_Longitude = 127.05666666666666;

    DT006 = &fix_list[259];
    fix_list[259].m_Latitude = 37.47858333333333;
    fix_list[259].m_Longitude = 126.88805555555557;

    DT007 = &fix_list[260];
    fix_list[260].m_Latitude = 37.462472222222225;
    fix_list[260].m_Longitude = 126.90819444444445;

    DT009 = &fix_list[261];
    fix_list[261].m_Latitude = 37.44336111111111;
    fix_list[261].m_Longitude = 126.93211111111111;

    DT034 = &fix_list[262];
    fix_list[262].m_Latitude = 37.27983333333333;
    fix_list[262].m_Longitude = 127.35508333333333;

    DT038 = &fix_list[263];
    fix_list[263].m_Latitude = 37.230333333333334;
    fix_list[263].m_Longitude = 127.44430555555556;

    DT043 = &fix_list[264];
    fix_list[264].m_Latitude = 36.962694444444445;
    fix_list[264].m_Longitude = 127.25033333333333;

    DU002 = &fix_list[265];
    fix_list[265].m_Latitude = 37.596000000000004;
    fix_list[265].m_Longitude = 126.74072222222222;

    DU004 = &fix_list[266];
    fix_list[266].m_Latitude = 37.61638888888889;
    fix_list[266].m_Longitude = 126.71508333333334;

    DU009 = &fix_list[267];
    fix_list[267].m_Latitude = 37.6755;
    fix_list[267].m_Longitude = 126.64061111111111;

    DU018 = &fix_list[268];
    fix_list[268].m_Latitude = 37.569361111111114;
    fix_list[268].m_Longitude = 126.50741666666667;

    DU022 = &fix_list[269];
    fix_list[269].m_Latitude = 37.498222222222225;
    fix_list[269].m_Longitude = 126.59669444444444;

    DUDOT = &fix_list[270];
    fix_list[270].m_Latitude = 37.486666666666665;
    fix_list[270].m_Longitude = 126.7;

    DU030 = &fix_list[271];
    fix_list[271].m_Latitude = 37.45783333333333;
    fix_list[271].m_Longitude = 126.80122222222222;

    DU063 = &fix_list[272];
    fix_list[272].m_Latitude = 37.230333333333334;
    fix_list[272].m_Longitude = 127.44430555555556;

    UPKIG = &fix_list[273];
    fix_list[273].m_Latitude = 37.023777777777774;
    fix_list[273].m_Longitude = 127.32122222222222;

    DUBAN = &fix_list[274];
    fix_list[274].m_Latitude = 27.937833333333334;
    fix_list[274].m_Longitude = 123.69033333333334;

    DUBUN = &fix_list[275];
    fix_list[275].m_Latitude = 38.087361111111115;
    fix_list[275].m_Longitude = 128.87050000000002;

    DUKAL = &fix_list[276];
    fix_list[276].m_Latitude = 33.649610833333334;
    fix_list[276].m_Longitude = 126.7607775;

    DUMAN = &fix_list[277];
    fix_list[277].m_Latitude = 38.51958055555556;
    fix_list[277].m_Longitude = 124.28032694444444;

    PEDVA = &fix_list[278];
    fix_list[278].m_Latitude = 35.636944444444445;
    fix_list[278].m_Longitude = 128.13172222222224;

    DY019 = &fix_list[279];
    fix_list[279].m_Latitude = 37.18666666666666;
    fix_list[279].m_Longitude = 126.66333333333334;

    DY020 = &fix_list[280];
    fix_list[280].m_Latitude = 37.34513888888889;
    fix_list[280].m_Longitude = 126.39802777777778;

    DY025 = &fix_list[281];
    fix_list[281].m_Latitude = 37.157222222222224;
    fix_list[281].m_Longitude = 126.35983333333333;

    DY027 = &fix_list[282];
    fix_list[282].m_Latitude = 37.11638888888889;
    fix_list[282].m_Longitude = 126.39597222222223;

    DY016 = &fix_list[283];
    fix_list[283].m_Latitude = 37.236222222222224;
    fix_list[283].m_Longitude = 126.49466666666667;

    DY017 = &fix_list[284];
    fix_list[284].m_Latitude = 37.29069444444444;
    fix_list[284].m_Longitude = 126.44638888888889;

    DY034 = &fix_list[285];
    fix_list[285].m_Latitude = 36.95505555555556;
    fix_list[285].m_Longitude = 126.7696111111111;

    DY037 = &fix_list[286];
    fix_list[286].m_Latitude = 36.93680555555555;
    fix_list[286].m_Longitude = 126.88566666666668;

    EG020 = &fix_list[287];
    fix_list[287].m_Latitude = 37.55877777777778;
    fix_list[287].m_Longitude = 126.37347222222222;

    EG040 = &fix_list[288];
    fix_list[288].m_Latitude = 37.64094444444444;
    fix_list[288].m_Longitude = 126.34419444444444;

    EG070 = &fix_list[289];
    fix_list[289].m_Latitude = 37.641444444444446;
    fix_list[289].m_Longitude = 126.54683333333332;

    EG140 = &fix_list[290];
    fix_list[290].m_Latitude = 37.41319444444444;
    fix_list[290].m_Longitude = 126.8073611111111;

    EG160 = &fix_list[291];
    fix_list[291].m_Latitude = 37.31988888888889;
    fix_list[291].m_Longitude = 126.89572222222223;

    EGOBA = &fix_list[292];
    fix_list[292].m_Latitude = 37.48741666666667;
    fix_list[292].m_Longitude = 127.37941666666666;

    EGOMI = &fix_list[293];
    fix_list[293].m_Latitude = 33.206944444444446;
    fix_list[293].m_Longitude = 126.54472222222222;

    EKIVA = &fix_list[294];
    fix_list[294].m_Latitude = 36.23863888888889;
    fix_list[294].m_Longitude = 126.53683333333333;

    EKVIK = &fix_list[295];
    fix_list[295].m_Latitude = 39.747680833333334;
    fix_list[295].m_Longitude = 136.60520583333332;

    ELAPI = &fix_list[296];
    fix_list[296].m_Latitude = 36.34470944444445;
    fix_list[296].m_Longitude = 128.83780611111112;

    ELGEP = &fix_list[297];
    fix_list[297].m_Latitude = 31.781388888888888;
    fix_list[297].m_Longitude = 125.93805555555556;

    ELGUK = &fix_list[298];
    fix_list[298].m_Latitude = 37.33316666666667;
    fix_list[298].m_Longitude = 125.7568611111111;

    ELMAP = &fix_list[299];
    fix_list[299].m_Latitude = 37.27111111111111;
    fix_list[299].m_Longitude = 127.18747222222223;

    ELPEX = &fix_list[300];
    fix_list[300].m_Latitude = 35.371251111111114;
    fix_list[300].m_Longitude = 126.98578361111112;

    ELPOS = &fix_list[301];
    fix_list[301].m_Latitude = 35.90274611111111;
    fix_list[301].m_Longitude = 126.78537388888888;

    EMRET = &fix_list[302];
    fix_list[302].m_Latitude = 28.005666666666666;
    fix_list[302].m_Longitude = 123.69033333333334;

    EMTIK = &fix_list[303];
    fix_list[303].m_Latitude = 35.94830555555555;
    fix_list[303].m_Longitude = 129.31938888888888;

    ENBUK = &fix_list[304];
    fix_list[304].m_Latitude = 37.39194444444444;
    fix_list[304].m_Longitude = 126.52188888888888;

    ENGOT = &fix_list[305];
    fix_list[305].m_Latitude = 34.809444444444445;
    fix_list[305].m_Longitude = 128.49777777777777;

    ENPIL = &fix_list[306];
    fix_list[306].m_Latitude = 37.16083333333333;
    fix_list[306].m_Longitude = 126.72611111111111;

    ENSAL = &fix_list[307];
    fix_list[307].m_Latitude = 36.931666666666665;
    fix_list[307].m_Longitude = 127.79638888888888;

    ENSUM = &fix_list[308];
    fix_list[308].m_Latitude = 32.217222222222226;
    fix_list[308].m_Longitude = 124.77638888888889;

    ENTEL = &fix_list[309];
    fix_list[309].m_Latitude = 36.386249722222225;
    fix_list[309].m_Longitude = 126.95138861111111;

    ESBIS = &fix_list[310];
    fix_list[310].m_Latitude = 31.253426944444445;
    fix_list[310].m_Longitude = 127.38132499999999;

    ESBOS = &fix_list[311];
    fix_list[311].m_Latitude = 36.77908333333333;
    fix_list[311].m_Longitude = 127.78727777777777;

    ORUSA = &fix_list[312];
    fix_list[312].m_Latitude = 35.290277777777774;
    fix_list[312].m_Longitude = 127.10402777777777;

    GAEBI = &fix_list[313];
    fix_list[313].m_Latitude = 33.45805527777778;
    fix_list[313].m_Longitude = 126.63166694444443;

    GALDI = &fix_list[314];
    fix_list[314].m_Latitude = 42.569436111111116;
    fix_list[314].m_Longitude = 131.19556666666668;

    GAPHA = &fix_list[315];
    fix_list[315].m_Latitude = 33.15913888888889;
    fix_list[315].m_Longitude = 126.69272166666667;

    GAYHA = &fix_list[316];
    fix_list[316].m_Latitude = 35.22288888888889;
    fix_list[316].m_Longitude = 128.63177777777778;

    GAZIN = &fix_list[317];
    fix_list[317].m_Latitude = 38.86666666666667;
    fix_list[317].m_Longitude = 131.5;

    GC003 = &fix_list[318];
    fix_list[318].m_Latitude = 37.52477777777778;
    fix_list[318].m_Longitude = 126.40380555555556;

    GC001 = &fix_list[319];
    fix_list[319].m_Latitude = 37.50436111111111;
    fix_list[319].m_Longitude = 126.42198333333334;

    GC021 = &fix_list[320];
    fix_list[320].m_Latitude = 37.67086111111111;
    fix_list[320].m_Longitude = 126.4985;

    GC022 = &fix_list[321];
    fix_list[321].m_Latitude = 37.6475;
    fix_list[321].m_Longitude = 126.57177777777777;

    GC034 = &fix_list[322];
    fix_list[322].m_Latitude = 37.36416666666667;
    fix_list[322].m_Longitude = 126.455;

    GC036 = &fix_list[323];
    fix_list[323].m_Latitude = 37.54563888888889;
    fix_list[323].m_Longitude = 126.74575;

    GC071 = &fix_list[324];
    fix_list[324].m_Latitude = 37.49402777777778;
    fix_list[324].m_Longitude = 127.42047222222223;

    GC072 = &fix_list[325];
    fix_list[325].m_Latitude = 37.33361111111111;
    fix_list[325].m_Longitude = 127.42005555555556;

    GE008 = &fix_list[326];
    fix_list[326].m_Latitude = 37.34905555555556;
    fix_list[326].m_Longitude = 126.55991666666667;

    GE016 = &fix_list[327];
    fix_list[327].m_Latitude = 37.34733333333334;
    fix_list[327].m_Longitude = 126.6893888888889;

    GE017 = &fix_list[328];
    fix_list[328].m_Latitude = 37.29275;
    fix_list[328].m_Longitude = 126.73752777777779;

    GE020 = &fix_list[329];
    fix_list[329].m_Latitude = 37.238194444444446;
    fix_list[329].m_Longitude = 126.78561111111111;

    GE022 = &fix_list[330];
    fix_list[330].m_Latitude = 37.38763888888889;
    fix_list[330].m_Longitude = 126.76122222222222;

    GE023 = &fix_list[331];
    fix_list[331].m_Latitude = 37.34077777777778;
    fix_list[331].m_Longitude = 126.82297222222222;

    GE024 = &fix_list[332];
    fix_list[332].m_Latitude = 37.18358333333333;
    fix_list[332].m_Longitude = 126.83361111111111;

    GE027 = &fix_list[333];
    fix_list[333].m_Latitude = 37.081;
    fix_list[333].m_Longitude = 126.79630555555555;

    GE028 = &fix_list[334];
    fix_list[334].m_Latitude = 37.128972222222224;
    fix_list[334].m_Longitude = 126.88152777777778;

    GE041 = &fix_list[335];
    fix_list[335].m_Latitude = 37.105444444444444;
    fix_list[335].m_Longitude = 127.12802777777777;

    GE046 = &fix_list[336];
    fix_list[336].m_Latitude = 37.199888888888886;
    fix_list[336].m_Longitude = 127.31619444444445;

    GEOJE = &fix_list[337];
    fix_list[337].m_Latitude = 35.015416944444446;
    fix_list[337].m_Longitude = 128.72833277777778;

    GH034 = &fix_list[338];
    fix_list[338].m_Latitude = 37.264944444444446;
    fix_list[338].m_Longitude = 126.46041666666667;

    GODIS = &fix_list[339];
    fix_list[339].m_Latitude = 35.65852777777778;
    fix_list[339].m_Longitude = 129.34286111111112;

    GOMUX = &fix_list[340];
    fix_list[340].m_Latitude = 35.22369444444445;
    fix_list[340].m_Longitude = 126.87847222222221;

    OLRIB = &fix_list[341];
    fix_list[341].m_Latitude = 36.02983333333333;
    fix_list[341].m_Longitude = 128.41150000000002;

    GOGET = &fix_list[342];
    fix_list[342].m_Latitude = 37.41166666666666;
    fix_list[342].m_Longitude = 126.51;

    GOKAK = &fix_list[343];
    fix_list[343].m_Latitude = 37.35066666666667;
    fix_list[343].m_Longitude = 126.55847222222222;

    GASAN = &fix_list[344];
    fix_list[344].m_Latitude = 39.731944444444444;
    fix_list[344].m_Longitude = 125.44472222222223;

    GOMAR = &fix_list[345];
    fix_list[345].m_Latitude = 32.46241694444445;
    fix_list[345].m_Longitude = 127.85799499999999;

    GONAV = &fix_list[346];
    fix_list[346].m_Latitude = 37.18011055555555;
    fix_list[346].m_Longitude = 124.41461027777778;

    GONAX = &fix_list[347];
    fix_list[347].m_Latitude = 36.386388333333336;
    fix_list[347].m_Longitude = 126.8377775;

    GONEE = &fix_list[348];
    fix_list[348].m_Latitude = 33.44333222222222;
    fix_list[348].m_Longitude = 126.86166694444444;

    GONYA = &fix_list[349];
    fix_list[349].m_Latitude = 34.981699722222224;
    fix_list[349].m_Longitude = 127.93040277777779;

    GOSBO = &fix_list[350];
    fix_list[350].m_Latitude = 34.25329166666667;
    fix_list[350].m_Longitude = 127.79108166666667;

    GOSIM = &fix_list[351];
    fix_list[351].m_Latitude = 39.0326325;
    fix_list[351].m_Longitude = 130.718855;

    GOURA = &fix_list[352];
    fix_list[352].m_Latitude = 33.69203444444444;
    fix_list[352].m_Longitude = 129.28079833333334;

    GOVLI = &fix_list[353];
    fix_list[353].m_Latitude = 35.98905555555556;
    fix_list[353].m_Longitude = 129.52772222222222;

    GT006 = &fix_list[354];
    fix_list[354].m_Latitude = 37.478388888888894;
    fix_list[354].m_Longitude = 126.89413888888889;

    GT007 = &fix_list[355];
    fix_list[355].m_Latitude = 37.463166666666666;
    fix_list[355].m_Longitude = 126.91305555555556;

    GT009 = &fix_list[356];
    fix_list[356].m_Latitude = 37.44425;
    fix_list[356].m_Longitude = 126.93672222222223;

    GT044 = &fix_list[357];
    fix_list[357].m_Latitude = 37.17080555555555;
    fix_list[357].m_Longitude = 127.55127777777777;

    GU002 = &fix_list[358];
    fix_list[358].m_Latitude = 37.59838888888889;
    fix_list[358].m_Longitude = 126.7435;

    GU004 = &fix_list[359];
    fix_list[359].m_Latitude = 37.61863888888889;
    fix_list[359].m_Longitude = 126.718;

    GU009 = &fix_list[360];
    fix_list[360].m_Latitude = 37.67777777777778;
    fix_list[360].m_Longitude = 126.6435;

    GU069 = &fix_list[361];
    fix_list[361].m_Latitude = 37.17080555555555;
    fix_list[361].m_Longitude = 127.55127777777777;

    GUKDO = &fix_list[362];
    fix_list[362].m_Latitude = 37.01969333333333;
    fix_list[362].m_Longitude = 127.639695;

    GUKSU = &fix_list[363];
    fix_list[363].m_Latitude = 33.880833611111115;
    fix_list[363].m_Longitude = 126.7325;

    GUMSA = &fix_list[364];
    fix_list[364].m_Latitude = 39.56888888888889;
    fix_list[364].m_Longitude = 127.43222222222222;

    GUKOB = &fix_list[365];
    fix_list[365].m_Latitude = 37.10563444444445;
    fix_list[365].m_Longitude = 127.13386722222224;

    UNTOM = &fix_list[366];
    fix_list[366].m_Latitude = 37.252609166666666;
    fix_list[366].m_Longitude = 127.10782916666666;

    KALIN = &fix_list[367];
    fix_list[367].m_Latitude = 37.33600833333334;
    fix_list[367].m_Longitude = 127.11111;

    UNVET = &fix_list[368];
    fix_list[368].m_Latitude = 37.41738722222222;
    fix_list[368].m_Longitude = 127.11431444444443;

    SANIB = &fix_list[369];
    fix_list[369].m_Latitude = 37.24301111111111;
    fix_list[369].m_Longitude = 127.07693277777777;

    BORNU = &fix_list[370];
    fix_list[370].m_Latitude = 37.32562416666667;
    fix_list[370].m_Longitude = 127.09159666666666;

    WADIO = &fix_list[371];
    fix_list[371].m_Latitude = 37.41586916666667;
    fix_list[371].m_Longitude = 127.10764777777777;

    TORIA = &fix_list[372];
    fix_list[372].m_Latitude = 37.63399277777778;
    fix_list[372].m_Longitude = 127.3585036111111;

    BUNDA = &fix_list[373];
    fix_list[373].m_Latitude = 37.654514166666665;
    fix_list[373].m_Longitude = 127.1502375;

    SCURU = &fix_list[374];
    fix_list[374].m_Latitude = 37.5719125;
    fix_list[374].m_Longitude = 127.13548083333335;

    MILOO = &fix_list[375];
    fix_list[375].m_Latitude = 37.48452638888889;
    fix_list[375].m_Longitude = 127.11988166666666;

    GUNKU = &fix_list[376];
    fix_list[376].m_Latitude = 36.57055555555556;
    fix_list[376].m_Longitude = 126.99694444444445;

    GUPLA = &fix_list[377];
    fix_list[377].m_Latitude = 35.12716666666667;
    fix_list[377].m_Longitude = 126.23836111111112;

    HAEGU = &fix_list[378];
    fix_list[378].m_Latitude = 35.53519444444444;
    fix_list[378].m_Longitude = 129.54230555555554;

    HAEUN = &fix_list[379];
    fix_list[379].m_Latitude = 35.18994444444444;
    fix_list[379].m_Longitude = 129.6826111111111;

    HALNA = &fix_list[380];
    fix_list[380].m_Latitude = 34.53375583333333;
    fix_list[380].m_Longitude = 131.53640777777778;

    HALUN = &fix_list[381];
    fix_list[381].m_Latitude = 35.74027777777778;
    fix_list[381].m_Longitude = 126.67119444444445;

    HAMUN = &fix_list[382];
    fix_list[382].m_Latitude = 39.92166666666667;
    fix_list[382].m_Longitude = 127.51833333333333;

    HANAB = &fix_list[383];
    fix_list[383].m_Latitude = 38.42652472222222;
    fix_list[383].m_Longitude = 138.032375;

    HANEE = &fix_list[384];
    fix_list[384].m_Latitude = 37.518055555555556;
    fix_list[384].m_Longitude = 126.30806111111112;

    HD050 = &fix_list[385];
    fix_list[385].m_Latitude = 37.38572222222222;
    fix_list[385].m_Longitude = 126.48436111111111;

    HD100 = &fix_list[386];
    fix_list[386].m_Latitude = 37.27972222222222;
    fix_list[386].m_Longitude = 126.52027777777778;

    HEDOD = &fix_list[387];
    fix_list[387].m_Latitude = 35.68125;
    fix_list[387].m_Longitude = 126.7436388888889;

    HP121 = &fix_list[388];
    fix_list[388].m_Latitude = 37.1025;
    fix_list[388].m_Longitude = 126.0978611111111;

    HUPHO = &fix_list[389];
    fix_list[389].m_Latitude = 36.60194444444445;
    fix_list[389].m_Longitude = 129.5293888888889;

    HWANI = &fix_list[390];
    fix_list[390].m_Latitude = 35.18889194444444;
    fix_list[390].m_Longitude = 128.24684194444444;

    HYEIN = &fix_list[391];
    fix_list[391].m_Latitude = 36.96308333333334;
    fix_list[391].m_Longitude = 127.62491666666666;

    OSNOP = &fix_list[392];
    fix_list[392].m_Latitude = 36.000194444444446;
    fix_list[392].m_Longitude = 128.0571111111111;

    ICHE = &fix_list[393];
    fix_list[393].m_Latitude = 33.49844388888889;
    fix_list[393].m_Longitude = 126.46566694444445;

    ICHG = &fix_list[394];
    fix_list[394].m_Latitude = 36.708333055555556;
    fix_list[394].m_Longitude = 127.48405611111112;

    ICHJ = &fix_list[395];
    fix_list[395].m_Latitude = 36.72683305555556;
    fix_list[395].m_Longitude = 127.51391694444445;

    ICJU = &fix_list[396];
    fix_list[396].m_Latitude = 33.51630611111111;
    fix_list[396].m_Longitude = 126.5004438888889;

    IDAG = &fix_list[397];
    fix_list[397].m_Latitude = 35.90322194444445;
    fix_list[397].m_Longitude = 128.6436111111111;

    IDIVU = &fix_list[398];
    fix_list[398].m_Latitude = 35.147888888888886;
    fix_list[398].m_Longitude = 128.9433888888889;

    IDROL = &fix_list[399];
    fix_list[399].m_Latitude = 34.87580555555556;
    fix_list[399].m_Longitude = 127.6008611111111;

    IDVIT = &fix_list[400];
    fix_list[400].m_Latitude = 35.08775;
    fix_list[400].m_Longitude = 126.38213888888889;

    IGASA = &fix_list[401];
    fix_list[401].m_Latitude = 36.13622222222222;
    fix_list[401].m_Longitude = 129.27127777777778;

    IGDOK = &fix_list[402];
    fix_list[402].m_Latitude = 35.513579722222225;
    fix_list[402].m_Longitude = 127.82136638888889;

    IGMEL = &fix_list[403];
    fix_list[403].m_Latitude = 35.63825;
    fix_list[403].m_Longitude = 129.34066666666666;

    IGPER = &fix_list[404];
    fix_list[404].m_Latitude = 37.52583333333333;
    fix_list[404].m_Longitude = 126.40277777777779;

    IGROD = &fix_list[405];
    fix_list[405].m_Latitude = 41.64999944444445;
    fix_list[405].m_Longitude = 136.7833327777778;

    IJDG = &fix_list[406];
    fix_list[406].m_Latitude = 33.40630611111111;
    fix_list[406].m_Longitude = 126.7114438888889;

    IKADI = &fix_list[407];
    fix_list[407].m_Latitude = 34.104;
    fix_list[407].m_Longitude = 123.47266666666667;

    IKAPO = &fix_list[408];
    fix_list[408].m_Latitude = 36.671277777777775;
    fix_list[408].m_Longitude = 127.75727777777777;

    IKEDO = &fix_list[409];
    fix_list[409].m_Latitude = 31.720555555555553;
    fix_list[409].m_Longitude = 125.66333333333334;

    IKEKA = &fix_list[410];
    fix_list[410].m_Latitude = 36.831388888888895;
    fix_list[410].m_Longitude = 123.35416666666666;

    IKESI = &fix_list[411];
    fix_list[411].m_Latitude = 35.148583333333335;
    fix_list[411].m_Longitude = 128.94097222222223;

    IKHE = &fix_list[412];
    fix_list[412].m_Latitude = 35.19672194444444;
    fix_list[412].m_Longitude = 128.93708305555555;

    IKMA = &fix_list[413];
    fix_list[413].m_Latitude = 35.196528055555554;
    fix_list[413].m_Longitude = 128.93477805555557;

    IKMO = &fix_list[414];
    fix_list[414].m_Latitude = 37.57038888888889;
    fix_list[414].m_Longitude = 126.77294388888889;

    IKPO = &fix_list[415];
    fix_list[415].m_Latitude = 35.988083055555556;
    fix_list[415].m_Longitude = 129.434;

    IKUMU = &fix_list[416];
    fix_list[416].m_Latitude = 34.94419194444444;
    fix_list[416].m_Longitude = 127.919925;

    IKUZ = &fix_list[417];
    fix_list[417].m_Latitude = 35.91874694444444;
    fix_list[417].m_Longitude = 126.6123311111111;

    IMAN = &fix_list[418];
    fix_list[418].m_Latitude = 34.97638888888889;
    fix_list[418].m_Longitude = 126.38291694444443;

    IMDG = &fix_list[419];
    fix_list[419].m_Latitude = 35.13916666666667;
    fix_list[419].m_Longitude = 126.81916666666666;

    IMDH = &fix_list[420];
    fix_list[420].m_Latitude = 35.11230611111111;
    fix_list[420].m_Longitude = 126.8003611111111;

    IMUN = &fix_list[421];
    fix_list[421].m_Latitude = 35.006416944444446;
    fix_list[421].m_Longitude = 126.38272194444444;

    INLL = &fix_list[422];
    fix_list[422].m_Latitude = 37.48394388888889;
    fix_list[422].m_Longitude = 126.43441694444445;

    INRR = &fix_list[423];
    fix_list[423].m_Latitude = 37.486111111111114;
    fix_list[423].m_Longitude = 126.43822194444445;

    IOFR = &fix_list[424];
    fix_list[424].m_Latitude = 37.545971944444446;
    fix_list[424].m_Longitude = 126.80358305555555;

    INTUT = &fix_list[425];
    fix_list[425].m_Latitude = 35.762277777777776;
    fix_list[425].m_Longitude = 128.89494444444443;

    IPDAS = &fix_list[426];
    fix_list[426].m_Latitude = 34.25436083333334;
    fix_list[426].m_Longitude = 126.71705555555556;

    IPKOL = &fix_list[427];
    fix_list[427].m_Latitude = 37.618722222222225;
    fix_list[427].m_Longitude = 126.28536111111111;

    LILVI = &fix_list[428];
    fix_list[428].m_Latitude = 35.21877777777778;
    fix_list[428].m_Longitude = 126.87502777777777;

    IRFN = &fix_list[429];
    fix_list[429].m_Latitude = 37.47094416666667;
    fix_list[429].m_Longitude = 126.41145;

    IRFS = &fix_list[430];
    fix_list[430].m_Latitude = 37.439009444444444;
    fix_list[430].m_Longitude = 126.4398675;

    IRKN = &fix_list[431];
    fix_list[431].m_Latitude = 37.47491222222222;
    fix_list[431].m_Longitude = 126.41366027777778;

    IRKS = &fix_list[432];
    fix_list[432].m_Latitude = 37.44116888888889;
    fix_list[432].m_Longitude = 126.44366555555555;

    ISAKY = &fix_list[433];
    fix_list[433].m_Latitude = 33.206185833333336;
    fix_list[433].m_Longitude = 129.65300277777777;

    ISAM = &fix_list[434];
    fix_list[434].m_Latitude = 35.097388888888894;
    fix_list[434].m_Longitude = 128.0838888888889;

    ISDOV = &fix_list[435];
    fix_list[435].m_Latitude = 34.79888888888889;
    fix_list[435].m_Longitude = 127.49861111111112;

    ISEL = &fix_list[436];
    fix_list[436].m_Latitude = 37.545693888888884;
    fix_list[436].m_Longitude = 126.80966694444444;

    ISHA = &fix_list[437];
    fix_list[437].m_Latitude = 35.08127805555556;
    fix_list[437].m_Longitude = 128.05522194444447;

    ISKP = &fix_list[438];
    fix_list[438].m_Latitude = 37.57269388888889;
    fix_list[438].m_Longitude = 126.77572194444444;

    ISLL = &fix_list[439];
    fix_list[439].m_Latitude = 37.45422194444445;
    fix_list[439].m_Longitude = 126.46661111111112;

    ISOL = &fix_list[440];
    fix_list[440].m_Latitude = 37.42952805555555;
    fix_list[440].m_Longitude = 127.11008305555555;

    ISRIV = &fix_list[441];
    fix_list[441].m_Latitude = 34.90277777777778;
    fix_list[441].m_Longitude = 127.43;

    ISRR = &fix_list[442];
    fix_list[442].m_Latitude = 37.45204861111112;
    fix_list[442].m_Longitude = 126.46276944444445;

    ISUL = &fix_list[443];
    fix_list[443].m_Latitude = 37.43127805555555;
    fix_list[443].m_Longitude = 127.11486111111111;

    ITAG = &fix_list[444];
    fix_list[444].m_Latitude = 35.902249999999995;
    fix_list[444].m_Longitude = 128.6428611111111;

    ITGL = &fix_list[445];
    fix_list[445].m_Latitude = 35.885;
    fix_list[445].m_Longitude = 128.6740561111111;

    IUJN = &fix_list[446];
    fix_list[446].m_Latitude = 36.78733305555556;
    fix_list[446].m_Longitude = 129.45777805555554;

    IUJS = &fix_list[447];
    fix_list[447].m_Latitude = 36.76675;
    fix_list[447].m_Longitude = 129.46574999999999;

    IULS = &fix_list[448];
    fix_list[448].m_Latitude = 35.604528055555555;
    fix_list[448].m_Longitude = 129.3508061111111;

    IVPR = &fix_list[449];
    fix_list[449].m_Latitude = 35.88881555555555;
    fix_list[449].m_Longitude = 126.61942638888888;

    IYAN = &fix_list[450];
    fix_list[450].m_Latitude = 38.07211111111111;
    fix_list[450].m_Longitude = 128.6580561111111;

    IYSO = &fix_list[451];
    fix_list[451].m_Latitude = 34.83111111111111;
    fix_list[451].m_Longitude = 127.62277805555554;

    IYSU = &fix_list[452];
    fix_list[452].m_Latitude = 34.853611111111114;
    fix_list[452].m_Longitude = 127.61172194444444;

    IEODO = &fix_list[453];
    fix_list[453].m_Latitude = 32.122795;
    fix_list[453].m_Longitude = 125.18224472222222;

    JADOO = &fix_list[454];
    fix_list[454].m_Latitude = 35.409444444444446;
    fix_list[454].m_Longitude = 127.23972222222223;

    JALDA = &fix_list[455];
    fix_list[455].m_Latitude = 35.165771944444444;
    fix_list[455].m_Longitude = 128.3484688888889;

    JB701 = &fix_list[456];
    fix_list[456].m_Latitude = 34.886;
    fix_list[456].m_Longitude = 126.16952777777779;

    JB702 = &fix_list[457];
    fix_list[457].m_Latitude = 35.01247194444444;
    fix_list[457].m_Longitude = 126.35816694444443;

    JB703 = &fix_list[458];
    fix_list[458].m_Latitude = 35.18072194444444;
    fix_list[458].m_Longitude = 126.60569472222221;

    JB704 = &fix_list[459];
    fix_list[459].m_Latitude = 35.04899972222222;
    fix_list[459].m_Longitude = 126.693695;

    JB705 = &fix_list[460];
    fix_list[460].m_Latitude = 34.30408277777777;
    fix_list[460].m_Longitude = 126.71633277777778;

    JB706 = &fix_list[461];
    fix_list[461].m_Latitude = 34.470999722222224;
    fix_list[461].m_Longitude = 126.53169472222223;

    JB751 = &fix_list[462];
    fix_list[462].m_Latitude = 34.516082777777775;
    fix_list[462].m_Longitude = 126.79947194444445;

    JB752 = &fix_list[463];
    fix_list[463].m_Latitude = 34.72533277777778;
    fix_list[463].m_Longitude = 126.557945;

    JB753 = &fix_list[464];
    fix_list[464].m_Latitude = 34.883695;
    fix_list[464].m_Longitude = 126.37388888888889;

    JB754 = &fix_list[465];
    fix_list[465].m_Latitude = 35.02383277777778;
    fix_list[465].m_Longitude = 126.21011083333333;

    JB755 = &fix_list[466];
    fix_list[466].m_Latitude = 35.25372194444444;
    fix_list[466].m_Longitude = 126.71547194444445;

    JB801 = &fix_list[467];
    fix_list[467].m_Latitude = 35.09763888888889;
    fix_list[467].m_Longitude = 126.38208277777777;

    JB802 = &fix_list[468];
    fix_list[468].m_Latitude = 35.09672194444445;
    fix_list[468].m_Longitude = 126.22161083333333;

    JB803 = &fix_list[469];
    fix_list[469].m_Latitude = 34.97986083333333;
    fix_list[469].m_Longitude = 126.22272194444444;

    JB804 = &fix_list[470];
    fix_list[470].m_Latitude = 34.90555583333333;
    fix_list[470].m_Longitude = 126.30427777777777;

    JB805 = &fix_list[471];
    fix_list[471].m_Latitude = 34.67766694444444;
    fix_list[471].m_Longitude = 126.55302777777777;

    JB806 = &fix_list[472];
    fix_list[472].m_Latitude = 34.59247194444445;
    fix_list[472].m_Longitude = 126.64552777777779;

    JB807 = &fix_list[473];
    fix_list[473].m_Latitude = 34.500749722222224;
    fix_list[473].m_Longitude = 126.63591694444445;

    JB808 = &fix_list[474];
    fix_list[474].m_Latitude = 35.3815;
    fix_list[474].m_Longitude = 126.89280583333334;

    JB809 = &fix_list[475];
    fix_list[475].m_Latitude = 35.30477777777777;
    fix_list[475].m_Longitude = 126.78522194444444;

    JB851 = &fix_list[476];
    fix_list[476].m_Latitude = 34.85025;
    fix_list[476].m_Longitude = 126.38372194444445;

    JB852 = &fix_list[477];
    fix_list[477].m_Latitude = 34.85088888888889;
    fix_list[477].m_Longitude = 126.53469472222223;

    JB853 = &fix_list[478];
    fix_list[478].m_Latitude = 34.977583888888894;
    fix_list[478].m_Longitude = 126.68611083333333;

    JB854 = &fix_list[479];
    fix_list[479].m_Latitude = 34.849360833333336;
    fix_list[479].m_Longitude = 126.2035;

    JB855 = &fix_list[480];
    fix_list[480].m_Latitude = 34.97788888888889;
    fix_list[480].m_Longitude = 126.20241694444445;

    JB856 = &fix_list[481];
    fix_list[481].m_Latitude = 34.54505583333333;
    fix_list[481].m_Longitude = 126.53933277777777;

    JB857 = &fix_list[482];
    fix_list[482].m_Latitude = 34.442499999999995;
    fix_list[482].m_Longitude = 126.62980583333332;

    JB858 = &fix_list[483];
    fix_list[483].m_Latitude = 35.19036083333333;
    fix_list[483].m_Longitude = 126.60672194444444;

    JB859 = &fix_list[484];
    fix_list[484].m_Latitude = 35.33669472222223;
    fix_list[484].m_Longitude = 126.88791694444446;

    IPDUT = &fix_list[485];
    fix_list[485].m_Latitude = 35.35466666666667;
    fix_list[485].m_Longitude = 126.96819444444445;

    JENAM = &fix_list[486];
    fix_list[486].m_Latitude = 39.730000000000004;
    fix_list[486].m_Longitude = 126.29944444444445;

    JIKJI = &fix_list[487];
    fix_list[487].m_Latitude = 36.68944444444444;
    fix_list[487].m_Longitude = 127.65611111111112;

    JINRO = &fix_list[488];
    fix_list[488].m_Latitude = 36.160694444444445;
    fix_list[488].m_Longitude = 126.60597222222222;

    JJ221 = &fix_list[489];
    fix_list[489].m_Latitude = 34.98522222222223;
    fix_list[489].m_Longitude = 126.85188888888888;

    JJ222 = &fix_list[490];
    fix_list[490].m_Latitude = 35.267944444444446;
    fix_list[490].m_Longitude = 126.88038888888889;

    JJ223 = &fix_list[491];
    fix_list[491].m_Latitude = 35.21488888888889;
    fix_list[491].m_Longitude = 127.03752777777778;

    JJ224 = &fix_list[492];
    fix_list[492].m_Latitude = 34.93858333333333;
    fix_list[492].m_Longitude = 126.68191666666667;

    JJ321 = &fix_list[493];
    fix_list[493].m_Latitude = 35.34097222222223;
    fix_list[493].m_Longitude = 127.3603611111111;

    JJ322 = &fix_list[494];
    fix_list[494].m_Latitude = 34.62544444444445;
    fix_list[494].m_Longitude = 126.81116666666667;

    JJ323 = &fix_list[495];
    fix_list[495].m_Latitude = 35.000083333333336;
    fix_list[495].m_Longitude = 127.01158333333333;

    JJ401 = &fix_list[496];
    fix_list[496].m_Latitude = 35.22252777777778;
    fix_list[496].m_Longitude = 126.97663888888889;

    JJ402 = &fix_list[497];
    fix_list[497].m_Latitude = 35.178777777777775;
    fix_list[497].m_Longitude = 127.08691666666667;

    JJ403 = &fix_list[498];
    fix_list[498].m_Latitude = 34.82402777777778;
    fix_list[498].m_Longitude = 126.66983333333334;

    JJ481 = &fix_list[499];
    fix_list[499].m_Latitude = 34.944805555555554;
    fix_list[499].m_Longitude = 126.68091666666668;

    JJ501 = &fix_list[500];
    fix_list[500].m_Latitude = 35.248333333333335;
    fix_list[500].m_Longitude = 126.7148888888889;

    JJ502 = &fix_list[501];
    fix_list[501].m_Latitude = 35.36666666666667;
    fix_list[501].m_Longitude = 127.42658333333334;

    JJ503 = &fix_list[502];
    fix_list[502].m_Latitude = 35.275277777777774;
    fix_list[502].m_Longitude = 127.19161111111111;

    JJ504 = &fix_list[503];
    fix_list[503].m_Latitude = 35.00011111111111;
    fix_list[503].m_Longitude = 127.08152777777778;

    JJ581 = &fix_list[504];
    fix_list[504].m_Latitude = 34.94394444444444;
    fix_list[504].m_Longitude = 126.68275;

    JJ681 = &fix_list[505];
    fix_list[505].m_Latitude = 35.28586111111111;
    fix_list[505].m_Longitude = 126.92219444444444;

    JJ682 = &fix_list[506];
    fix_list[506].m_Latitude = 35.25694444444444;
    fix_list[506].m_Longitude = 126.90183333333334;

    JJ683 = &fix_list[507];
    fix_list[507].m_Latitude = 35.177388888888885;
    fix_list[507].m_Longitude = 126.84597222222222;

    JJ781 = &fix_list[508];
    fix_list[508].m_Latitude = 35.28675;
    fix_list[508].m_Longitude = 126.92033333333333;

    JJ782 = &fix_list[509];
    fix_list[509].m_Latitude = 35.25780555555556;
    fix_list[509].m_Longitude = 126.9;

    JJ783 = &fix_list[510];
    fix_list[510].m_Latitude = 35.17827777777777;
    fix_list[510].m_Longitude = 126.84413888888888;

    JONJU = &fix_list[511];
    fix_list[511].m_Latitude = 39.684999999999995;
    fix_list[511].m_Longitude = 125.21694444444445;

    JY401 = &fix_list[512];
    fix_list[512].m_Latitude = 34.97716666666667;
    fix_list[512].m_Longitude = 127.55111111111111;

    JY402 = &fix_list[513];
    fix_list[513].m_Latitude = 35.01213888888889;
    fix_list[513].m_Longitude = 127.44722222222222;

    JY752 = &fix_list[514];
    fix_list[514].m_Latitude = 34.39255555555555;
    fix_list[514].m_Longitude = 127.88388888888889;

    JY801 = &fix_list[515];
    fix_list[515].m_Latitude = 34.65152777777778;
    fix_list[515].m_Longitude = 127.71380583333334;

    JY802 = &fix_list[516];
    fix_list[516].m_Latitude = 34.609027777777776;
    fix_list[516].m_Longitude = 127.83016694444444;

    JY803 = &fix_list[517];
    fix_list[517].m_Latitude = 34.74030583333334;
    fix_list[517].m_Longitude = 127.90055583333334;

    JY804 = &fix_list[518];
    fix_list[518].m_Latitude = 34.81547194444444;
    fix_list[518].m_Longitude = 127.50624972222222;

    JY805 = &fix_list[519];
    fix_list[519].m_Latitude = 35.03941694444444;
    fix_list[519].m_Longitude = 127.36936083333333;

    JY806 = &fix_list[520];
    fix_list[520].m_Latitude = 34.42016666666667;
    fix_list[520].m_Longitude = 127.72516666666667;

    JY851 = &fix_list[521];
    fix_list[521].m_Latitude = 34.94391694444444;
    fix_list[521].m_Longitude = 127.56747194444443;

    JY852 = &fix_list[522];
    fix_list[522].m_Latitude = 34.991971944444444;
    fix_list[522].m_Longitude = 127.71230583333333;

    JY853 = &fix_list[523];
    fix_list[523].m_Latitude = 34.89363888888889;
    fix_list[523].m_Longitude = 127.76030583333333;

    JY854 = &fix_list[524];
    fix_list[524].m_Latitude = 34.71313888888889;
    fix_list[524].m_Longitude = 127.65761083333334;

    JY857 = &fix_list[525];
    fix_list[525].m_Latitude = 34.78486083333333;
    fix_list[525].m_Longitude = 127.69833277777778;

    JY865 = &fix_list[526];
    fix_list[526].m_Latitude = 34.79958333333333;
    fix_list[526].m_Longitude = 127.51752777777777;

    JY866 = &fix_list[527];
    fix_list[527].m_Latitude = 34.68388888888889;
    fix_list[527].m_Longitude = 127.56363888888889;

    KABVO = &fix_list[528];
    fix_list[528].m_Latitude = 35.08601388888889;
    fix_list[528].m_Longitude = 128.35978083333333;

    KADIL = &fix_list[529];
    fix_list[529].m_Latitude = 35.98663888888889;
    fix_list[529].m_Longitude = 129.30441666666667;

    KAGOK = &fix_list[530];
    fix_list[530].m_Latitude = 37.228833333333334;
    fix_list[530].m_Longitude = 126.62616666666666;

    KAIFA = &fix_list[531];
    fix_list[531].m_Latitude = 35.07455277777778;
    fix_list[531].m_Longitude = 128.04709194444445;

    KAKPU = &fix_list[532];
    fix_list[532].m_Latitude = 41.46138888888889;
    fix_list[532].m_Longitude = 130.47305555555556;

    KAKRU = &fix_list[533];
    fix_list[533].m_Latitude = 34.92986111111111;
    fix_list[533].m_Longitude = 127.57433333333333;

    KAKSO = &fix_list[534];
    fix_list[534].m_Latitude = 37.12905527777778;
    fix_list[534].m_Longitude = 127.44372194444445;

    KALMA = &fix_list[535];
    fix_list[535].m_Latitude = 37.3125;
    fix_list[535].m_Longitude = 127.11249972222221;

    KALOD = &fix_list[536];
    fix_list[536].m_Latitude = 35.503013333333335;
    fix_list[536].m_Longitude = 128.77358;

    KALUS = &fix_list[537];
    fix_list[537].m_Latitude = 35.69372222222222;
    fix_list[537].m_Longitude = 129.32080555555555;

    KAMIT = &fix_list[538];
    fix_list[538].m_Latitude = 34.253888333333336;
    fix_list[538].m_Longitude = 126.77166611111112;

    KAMSA = &fix_list[539];
    fix_list[539].m_Latitude = 37.71805555555556;
    fix_list[539].m_Longitude = 133.7338883333333;

    KANKA = &fix_list[540];
    fix_list[540].m_Latitude = 31.531944444444445;
    fix_list[540].m_Longitude = 125.58444416666666;

    KARBU = &fix_list[541];
    fix_list[541].m_Latitude = 37.53308305555556;
    fix_list[541].m_Longitude = 127.66444416666667;

    KASKA = &fix_list[542];
    fix_list[542].m_Latitude = 28.706666388888888;
    fix_list[542].m_Longitude = 123.68299972222222;

    KASPU = &fix_list[543];
    fix_list[543].m_Latitude = 35.15208333333333;
    fix_list[543].m_Longitude = 126.38169444444443;

    KC001 = &fix_list[544];
    fix_list[544].m_Latitude = 37.502202777777775;
    fix_list[544].m_Longitude = 126.41816666666666;

    KC003 = &fix_list[545];
    fix_list[545].m_Latitude = 37.52261111111111;
    fix_list[545].m_Longitude = 126.39997222222223;

    KC066 = &fix_list[546];
    fix_list[546].m_Latitude = 37.233666666666664;
    fix_list[546].m_Longitude = 127.25522222222222;

    KC067 = &fix_list[547];
    fix_list[547].m_Latitude = 37.35041666666667;
    fix_list[547].m_Longitude = 127.31769444444444;

    KE008 = &fix_list[548];
    fix_list[548].m_Latitude = 37.34691666666667;
    fix_list[548].m_Longitude = 126.55608333333333;

    KE019 = &fix_list[549];
    fix_list[549].m_Latitude = 37.19961111111111;
    fix_list[549].m_Longitude = 126.68625;

    ESDEM = &fix_list[550];
    fix_list[550].m_Latitude = 36.03077777777778;
    fix_list[550].m_Longitude = 128.41230555555555;

    GE019 = &fix_list[551];
    fix_list[551].m_Latitude = 37.201750000000004;
    fix_list[551].m_Longitude = 126.69008333333333;

    KE035 = &fix_list[552];
    fix_list[552].m_Latitude = 37.27166666666667;
    fix_list[552].m_Longitude = 126.97311111111111;

    KE044 = &fix_list[553];
    fix_list[553].m_Latitude = 37.37327777777778;
    fix_list[553].m_Longitude = 127.27797222222222;

    KEVAP = &fix_list[554];
    fix_list[554].m_Latitude = 34.80302777777778;
    fix_list[554].m_Longitude = 126.38425000000001;

    KEVOX = &fix_list[555];
    fix_list[555].m_Latitude = 35.014361111111114;
    fix_list[555].m_Longitude = 128.72977777777777;

    KICHA = &fix_list[556];
    fix_list[556].m_Latitude = 40.68416666666666;
    fix_list[556].m_Longitude = 129.19222222222223;

    KIDAB = &fix_list[557];
    fix_list[557].m_Latitude = 37.38977777777778;
    fix_list[557].m_Longitude = 126.51808333333334;

    KIDOS = &fix_list[558];
    fix_list[558].m_Latitude = 33.84111111111111;
    fix_list[558].m_Longitude = 126.56722222222221;

    KIXIS = &fix_list[559];
    fix_list[559].m_Latitude = 35.998805555555556;
    fix_list[559].m_Longitude = 126.60947222222222;

    KM401 = &fix_list[560];
    fix_list[560].m_Latitude = 39.21823055555556;
    fix_list[560].m_Longitude = 127.44168055555556;

    KM402 = &fix_list[561];
    fix_list[561].m_Latitude = 39.246316666666665;
    fix_list[561].m_Longitude = 127.418525;

    KM403 = &fix_list[562];
    fix_list[562].m_Latitude = 39.27437777777778;
    fix_list[562].m_Longitude = 127.39536944444446;

    KM404 = &fix_list[563];
    fix_list[563].m_Latitude = 39.30247222222222;
    fix_list[563].m_Longitude = 127.37215555555555;

    KM405 = &fix_list[564];
    fix_list[564].m_Latitude = 39.401202777777776;
    fix_list[564].m_Longitude = 127.39436111111112;

    KM411 = &fix_list[565];
    fix_list[565].m_Latitude = 39.22067222222223;
    fix_list[565].m_Longitude = 127.44253888888889;

    KM412 = &fix_list[566];
    fix_list[566].m_Latitude = 39.248755555555555;
    fix_list[566].m_Longitude = 127.419375;

    KM413 = &fix_list[567];
    fix_list[567].m_Latitude = 39.276833333333336;
    fix_list[567].m_Longitude = 127.39619444444445;

    KM414 = &fix_list[568];
    fix_list[568].m_Latitude = 39.30490555555555;
    fix_list[568].m_Longitude = 127.37299444444444;

    KM501 = &fix_list[569];
    fix_list[569].m_Latitude = 39.09928888888889;
    fix_list[569].m_Longitude = 127.5395361111111;

    KM502 = &fix_list[570];
    fix_list[570].m_Latitude = 39.11143888888889;
    fix_list[570].m_Longitude = 127.56387222222222;

    KM503 = &fix_list[571];
    fix_list[571].m_Latitude = 39.123580555555556;
    fix_list[571].m_Longitude = 127.58821666666667;

    KM504 = &fix_list[572];
    fix_list[572].m_Latitude = 39.16240555555555;
    fix_list[572].m_Longitude = 127.66617500000001;

    KM505 = &fix_list[573];
    fix_list[573].m_Latitude = 39.31777777777778;
    fix_list[573].m_Longitude = 127.54555555555555;

    KM511 = &fix_list[574];
    fix_list[574].m_Latitude = 39.10031666666667;
    fix_list[574].m_Longitude = 127.54159166666666;

    KM601 = &fix_list[575];
    fix_list[575].m_Latitude = 39.353325;
    fix_list[575].m_Longitude = 127.45916111111111;

    KM701 = &fix_list[576];
    fix_list[576].m_Latitude = 39.30790277777778;
    fix_list[576].m_Longitude = 127.36760555555554;

    KM702 = &fix_list[577];
    fix_list[577].m_Latitude = 39.38605555555556;
    fix_list[577].m_Longitude = 127.38690555555556;

    GUMAK = &fix_list[578];
    fix_list[578].m_Latitude = 35.22858333333333;
    fix_list[578].m_Longitude = 126.87944444444443;

    KOTTY = &fix_list[579];
    fix_list[579].m_Latitude = 35.06222222222222;
    fix_list[579].m_Longitude = 126.56;

    KT018 = &fix_list[580];
    fix_list[580].m_Latitude = 37.42830555555555;
    fix_list[580].m_Longitude = 127.08641666666666;

    APOMO = &fix_list[581];
    fix_list[581].m_Latitude = 37.45580555555556;
    fix_list[581].m_Longitude = 127.18455555555556;

    KT033 = &fix_list[582];
    fix_list[582].m_Latitude = 37.34677777777778;
    fix_list[582].m_Longitude = 127.28808333333333;

    KUPER = &fix_list[583];
    fix_list[583].m_Latitude = 42.33804722222222;
    fix_list[583].m_Longitude = 132.19334722222223;

    LAPAL = &fix_list[584];
    fix_list[584].m_Latitude = 35.903527499999996;
    fix_list[584].m_Longitude = 129.08106361111112;

    LATUX = &fix_list[585];
    fix_list[585].m_Latitude = 35.48333277777778;
    fix_list[585].m_Longitude = 120.78333277777777;

    LEBUX = &fix_list[586];
    fix_list[586].m_Latitude = 35.81088888888888;
    fix_list[586].m_Longitude = 126.6463888888889;

    LEDIN = &fix_list[587];
    fix_list[587].m_Latitude = 33.545027777777776;
    fix_list[587].m_Longitude = 126.17080555555556;

    LEGAK = &fix_list[588];
    fix_list[588].m_Latitude = 37.05583333333333;
    fix_list[588].m_Longitude = 124.8308611111111;

    LEGUN = &fix_list[589];
    fix_list[589].m_Latitude = 37.304027777777776;
    fix_list[589].m_Longitude = 126.59405555555556;

    LENBI = &fix_list[590];
    fix_list[590].m_Latitude = 37.29105555555555;
    fix_list[590].m_Longitude = 126.57113888888888;

    LESBU = &fix_list[591];
    fix_list[591].m_Latitude = 37.687777777777775;
    fix_list[591].m_Longitude = 129.68444444444444;

    LIMDI = &fix_list[592];
    fix_list[592].m_Latitude = 33.55361111111111;
    fix_list[592].m_Longitude = 125.83138888888888;

    LIMSO = &fix_list[593];
    fix_list[593].m_Latitude = 33.4175;
    fix_list[593].m_Longitude = 126.3086111111111;

    LINTA = &fix_list[594];
    fix_list[594].m_Latitude = 35.52108333333333;
    fix_list[594].m_Longitude = 126.85527722222221;

    LOSNI = &fix_list[595];
    fix_list[595].m_Latitude = 33.55416666666667;
    fix_list[595].m_Longitude = 126.69805555555556;

    LOSTO = &fix_list[596];
    fix_list[596].m_Latitude = 36.33634722222222;
    fix_list[596].m_Longitude = 129.43112333333332;

    LUKKI = &fix_list[597];
    fix_list[597].m_Latitude = 35.99466666666667;
    fix_list[597].m_Longitude = 126.59422222222221;

    LUKLI = &fix_list[598];
    fix_list[598].m_Latitude = 35.431777777777775;
    fix_list[598].m_Longitude = 129.36522222222223;

    LUPAS = &fix_list[599];
    fix_list[599].m_Latitude = 42.23110277777778;
    fix_list[599].m_Longitude = 131.53334722222223;

    MABON = &fix_list[600];
    fix_list[600].m_Latitude = 35.02099694444444;
    fix_list[600].m_Longitude = 127.99804194444445;

    MAEMI = &fix_list[601];
    fix_list[601].m_Latitude = 34.88015;
    fix_list[601].m_Longitude = 127.85493888888888;

    MAKDU = &fix_list[602];
    fix_list[602].m_Latitude = 36.45162416666667;
    fix_list[602].m_Longitude = 127.81919027777778;

    MAKET = &fix_list[603];
    fix_list[603].m_Latitude = 33.91455555555555;
    fix_list[603].m_Longitude = 127.33138888888888;

    MAKKY = &fix_list[604];
    fix_list[604].m_Latitude = 35.87188888888889;
    fix_list[604].m_Longitude = 129.25994444444444;

    MAKSA = &fix_list[605];
    fix_list[605].m_Latitude = 35.503055833333335;
    fix_list[605].m_Longitude = 126.90611055555556;

    MAKUN = &fix_list[606];
    fix_list[606].m_Latitude = 35.78138888888889;
    fix_list[606].m_Longitude = 129.36466666666666;

    MALSO = &fix_list[607];
    fix_list[607].m_Latitude = 37.91111111111111;
    fix_list[607].m_Longitude = 131.81777777777776;

    MANBA = &fix_list[608];
    fix_list[608].m_Latitude = 33.72775;
    fix_list[608].m_Longitude = 126.32333333333332;

    MANGI = &fix_list[609];
    fix_list[609].m_Latitude = 35.503055;
    fix_list[609].m_Longitude = 126.74222222222222;

    MANOL = &fix_list[610];
    fix_list[610].m_Latitude = 33.60805555555556;
    fix_list[610].m_Longitude = 126.92055555555557;

    MARMI = &fix_list[611];
    fix_list[611].m_Latitude = 35.98652777777778;
    fix_list[611].m_Longitude = 129.29555555555555;

    MASTA = &fix_list[612];
    fix_list[612].m_Latitude = 35.47972222222222;
    fix_list[612].m_Longitude = 128.56111111111113;

    MATEN = &fix_list[613];
    fix_list[613].m_Latitude = 42.42499166666666;
    fix_list[613].m_Longitude = 132.18584722222224;

    MATIZ = &fix_list[614];
    fix_list[614].m_Latitude = 36.84302777777778;
    fix_list[614].m_Longitude = 127.42947222222223;

    DOVUR = &fix_list[615];
    fix_list[615].m_Latitude = 35.83025000000001;
    fix_list[615].m_Longitude = 128.77275;

    KABAS = &fix_list[616];
    fix_list[616].m_Latitude = 35.9475;
    fix_list[616].m_Longitude = 128.56097222222223;

    MEDIO = &fix_list[617];
    fix_list[617].m_Latitude = 39.48773083333334;
    fix_list[617].m_Longitude = 137.53890777777778;

    MEESA = &fix_list[618];
    fix_list[618].m_Latitude = 37.57885277777778;
    fix_list[618].m_Longitude = 127.24577194444444;

    MEKIL = &fix_list[619];
    fix_list[619].m_Latitude = 36.55611111111111;
    fix_list[619].m_Longitude = 126.83138888888888;

    MELES = &fix_list[620];
    fix_list[620].m_Latitude = 35.878949444444444;
    fix_list[620].m_Longitude = 127.26329638888889;

    MENIV = &fix_list[621];
    fix_list[621].m_Latitude = 34.59616694444445;
    fix_list[621].m_Longitude = 127.58552777777777;

    MENOL = &fix_list[622];
    fix_list[622].m_Latitude = 36.790277499999995;
    fix_list[622].m_Longitude = 127.78972222222222;

    JISUN = &fix_list[623];
    fix_list[623].m_Latitude = 35.12755555555555;
    fix_list[623].m_Longitude = 127.01538888888889;

    MEXER = &fix_list[624];
    fix_list[624].m_Latitude = 33.45777777777778;
    fix_list[624].m_Longitude = 126.38666666666667;

    MIGOL = &fix_list[625];
    fix_list[625].m_Latitude = 30.767;
    fix_list[625].m_Longitude = 123.68666666666667;

    MIKES = &fix_list[626];
    fix_list[626].m_Latitude = 29.586971944444443;
    fix_list[626].m_Longitude = 125.74816694444445;

    MOBAK = &fix_list[627];
    fix_list[627].m_Latitude = 37.40130527777777;
    fix_list[627].m_Longitude = 126.99033361111111;

    MONSI = &fix_list[628];
    fix_list[628].m_Latitude = 37.213055833333335;
    fix_list[628].m_Longitude = 126.83749999999999;

    MOXID = &fix_list[629];
    fix_list[629].m_Latitude = 36.386388333333336;
    fix_list[629].m_Longitude = 126.73305527777778;

    MUBIX = &fix_list[630];
    fix_list[630].m_Latitude = 34.90035777777778;
    fix_list[630].m_Longitude = 127.82851694444444;

    MUGAR = &fix_list[631];
    fix_list[631].m_Latitude = 37.295971944444446;
    fix_list[631].m_Longitude = 127.31905583333332;

    MUMUT = &fix_list[632];
    fix_list[632].m_Latitude = 37.525277777777774;
    fix_list[632].m_Longitude = 126.39750000000001;

    MARYO = &fix_list[633];
    fix_list[633].m_Latitude = 35.03516666666666;
    fix_list[633].m_Longitude = 126.74638888888889;

    MUNAN = &fix_list[634];
    fix_list[634].m_Latitude = 37.569250000000004;
    fix_list[634].m_Longitude = 126.19805555555556;

    MUPAS = &fix_list[635];
    fix_list[635].m_Latitude = 33.180305555555556;
    fix_list[635].m_Longitude = 126.51430555555555;

    NAISS = &fix_list[636];
    fix_list[636].m_Latitude = 35.16013888888889;
    fix_list[636].m_Longitude = 128.26477472222223;

    NAKZY = &fix_list[637];
    fix_list[637].m_Latitude = 35.21494416666667;
    fix_list[637].m_Longitude = 126.65961055555556;

    NARAE = &fix_list[638];
    fix_list[638].m_Latitude = 35.002360833333334;
    fix_list[638].m_Longitude = 129.12424972222223;

    NATEK = &fix_list[639];
    fix_list[639].m_Latitude = 42.663332499999996;
    fix_list[639].m_Longitude = 135.1394436111111;

    NEIAN = &fix_list[640];
    fix_list[640].m_Latitude = 35.06294444444444;
    fix_list[640].m_Longitude = 128.95430555555555;

    NIMAL = &fix_list[641];
    fix_list[641].m_Latitude = 38.07266666666667;
    fix_list[641].m_Longitude = 128.7666111111111;

    ESNEG = &fix_list[642];
    fix_list[642].m_Latitude = 37.17055555555555;
    fix_list[642].m_Longitude = 129.8475;

    NIPUT = &fix_list[643];
    fix_list[643].m_Latitude = 37.23097222222222;
    fix_list[643].m_Longitude = 126.62997222222222;

    NIRAT = &fix_list[644];
    fix_list[644].m_Latitude = 32.06494166666666;
    fix_list[644].m_Longitude = 126.05802555555556;

    NISAV = &fix_list[645];
    fix_list[645].m_Latitude = 34.25527777777778;
    fix_list[645].m_Longitude = 127.97638888888889;

    TEPEL = &fix_list[646];
    fix_list[646].m_Latitude = 35.028194444444445;
    fix_list[646].m_Longitude = 126.74152777777778;

    NOBOB = &fix_list[647];
    fix_list[647].m_Latitude = 35.82;
    fix_list[647].m_Longitude = 121.40833277777779;

    NOBUT = &fix_list[648];
    fix_list[648].m_Latitude = 37.119420833333336;
    fix_list[648].m_Longitude = 129.33606277777778;

    NODUN = &fix_list[649];
    fix_list[649].m_Latitude = 37.186138888888884;
    fix_list[649].m_Longitude = 127.34097222222222;

    NOGON = &fix_list[650];
    fix_list[650].m_Latitude = 37.38055555555555;
    fix_list[650].m_Longitude = 124.41805555555555;

    NOGUB = &fix_list[651];
    fix_list[651].m_Latitude = 37.34766666666667;
    fix_list[651].m_Longitude = 127.05716666666666;

    NULDI = &fix_list[652];
    fix_list[652].m_Latitude = 34.42055555555555;
    fix_list[652].m_Longitude = 126.6275;

    NUTBO = &fix_list[653];
    fix_list[653].m_Latitude = 37.510555555555555;
    fix_list[653].m_Longitude = 126.41638888888889;

    GT020 = &fix_list[654];
    fix_list[654].m_Latitude = 37.30716666666667;
    fix_list[654].m_Longitude = 127.10752777777778;

    NONOS = &fix_list[655];
    fix_list[655].m_Latitude = 36.67944416666666;
    fix_list[655].m_Longitude = 124.39805555555556;

    NOORI = &fix_list[656];
    fix_list[656].m_Latitude = 35.03055555555555;
    fix_list[656].m_Longitude = 128.7782777777778;

    NOPEN = &fix_list[657];
    fix_list[657].m_Latitude = 37.54819444444444;
    fix_list[657].m_Longitude = 126.38291666666666;

    NOPIK = &fix_list[658];
    fix_list[658].m_Latitude = 37.40333222222222;
    fix_list[658].m_Longitude = 125.65138861111112;

    ARIMU = &fix_list[659];
    fix_list[659].m_Latitude = 34.83441666666667;
    fix_list[659].m_Longitude = 126.78397222222222;

    NUKBA = &fix_list[660];
    fix_list[660].m_Latitude = 34.890991666666665;
    fix_list[660].m_Longitude = 128.5930638888889;

    NULAR = &fix_list[661];
    fix_list[661].m_Latitude = 40.98665833333333;
    fix_list[661].m_Longitude = 134.18334444444446;

    NUSLO = &fix_list[662];
    fix_list[662].m_Latitude = 33.26672222222222;
    fix_list[662].m_Longitude = 126.66994444444445;

    NY000 = &fix_list[663];
    fix_list[663].m_Latitude = 38.09597222222222;
    fix_list[663].m_Longitude = 128.63358333333332;

    NY003 = &fix_list[664];
    fix_list[664].m_Latitude = 38.013666666666666;
    fix_list[664].m_Longitude = 128.71797222222222;

    NY004 = &fix_list[665];
    fix_list[665].m_Latitude = 37.99461111111111;
    fix_list[665].m_Longitude = 128.7374722222222;

    NY010 = &fix_list[666];
    fix_list[666].m_Latitude = 37.92286111111111;
    fix_list[666].m_Longitude = 128.8107777777778;

    NY015 = &fix_list[667];
    fix_list[667].m_Latitude = 37.97533333333334;
    fix_list[667].m_Longitude = 128.89266666666666;

    NY031 = &fix_list[668];
    fix_list[668].m_Latitude = 38.05947222222222;
    fix_list[668].m_Longitude = 128.67383333333333;

    NY040 = &fix_list[669];
    fix_list[669].m_Latitude = 38.0575;
    fix_list[669].m_Longitude = 128.7545;

    NY042 = &fix_list[670];
    fix_list[670].m_Latitude = 37.874833333333335;
    fix_list[670].m_Longitude = 128.6736388888889;

    NY049 = &fix_list[671];
    fix_list[671].m_Latitude = 37.75311111111111;
    fix_list[671].m_Longitude = 128.67352777777776;

    NY050 = &fix_list[672];
    fix_list[672].m_Latitude = 37.97813888888889;
    fix_list[672].m_Longitude = 128.75433333333334;

    NY070 = &fix_list[673];
    fix_list[673].m_Latitude = 37.90252777777778;
    fix_list[673].m_Longitude = 128.75416666666666;

    NY090 = &fix_list[674];
    fix_list[674].m_Latitude = 37.81755555555556;
    fix_list[674].m_Longitude = 128.754;

    IGBEM = &fix_list[675];
    fix_list[675].m_Latitude = 35.12861111111111;
    fix_list[675].m_Longitude = 127.21286111111111;

    OKTUL = &fix_list[676];
    fix_list[676].m_Latitude = 34.96979972222223;
    fix_list[676].m_Longitude = 127.94594694444444;

    OLBES = &fix_list[677];
    fix_list[677].m_Latitude = 34.60225;
    fix_list[677].m_Longitude = 126.37555555555555;

    OLBIM = &fix_list[678];
    fix_list[678].m_Latitude = 37.23638888888889;
    fix_list[678].m_Longitude = 124.13083333333333;

    OLKIK = &fix_list[679];
    fix_list[679].m_Latitude = 37.61655555555556;
    fix_list[679].m_Longitude = 126.28152777777778;

    OLLEH = &fix_list[680];
    fix_list[680].m_Latitude = 33.96172166666667;
    fix_list[680].m_Longitude = 126.740695;

    OLMEN = &fix_list[681];
    fix_list[681].m_Latitude = 36.737055833333336;
    fix_list[681].m_Longitude = 126.99099972222223;

    OLMOG = &fix_list[682];
    fix_list[682].m_Latitude = 35.05891666666666;
    fix_list[682].m_Longitude = 128.95252777777776;

    OLMUD = &fix_list[683];
    fix_list[683].m_Latitude = 35.040277777777774;
    fix_list[683].m_Longitude = 128.8211111111111;

    OLNIG = &fix_list[684];
    fix_list[684].m_Latitude = 35.157830833333335;
    fix_list[684].m_Longitude = 128.19143083333333;

    OLTEM = &fix_list[685];
    fix_list[685].m_Latitude = 37.67172222222222;
    fix_list[685].m_Longitude = 126.34619444444444;

    OMKEL = &fix_list[686];
    fix_list[686].m_Latitude = 33.72116666666667;
    fix_list[686].m_Longitude = 126.68555583333334;

    OMKIM = &fix_list[687];
    fix_list[687].m_Latitude = 33.22222222222222;
    fix_list[687].m_Longitude = 126.68722222222223;

    OMOTU = &fix_list[688];
    fix_list[688].m_Latitude = 35.009166666666665;
    fix_list[688].m_Longitude = 128.83944444444447;

    ONAPU = &fix_list[689];
    fix_list[689].m_Latitude = 35.56511111111111;
    fix_list[689].m_Longitude = 129.3541111111111;

    ONATA = &fix_list[690];
    fix_list[690].m_Latitude = 38.47555555555556;
    fix_list[690].m_Longitude = 132.10055555555556;

    OPEDA = &fix_list[691];
    fix_list[691].m_Latitude = 35.864131111111114;
    fix_list[691].m_Longitude = 127.61271611111111;

    OPONO = &fix_list[692];
    fix_list[692].m_Latitude = 35.30672222222222;
    fix_list[692].m_Longitude = 128.7295;

    OSERI = &fix_list[693];
    fix_list[693].m_Latitude = 37.533055555555556;
    fix_list[693].m_Longitude = 126.35613888888888;

    OSIVI = &fix_list[694];
    fix_list[694].m_Latitude = 36.72327777777778;
    fix_list[694].m_Longitude = 127.36952777777778;

    OSPOT = &fix_list[695];
    fix_list[695].m_Latitude = 36.83836027777778;
    fix_list[695].m_Longitude = 127.34858277777778;

    OSROX = &fix_list[696];
    fix_list[696].m_Latitude = 35.25502777777778;
    fix_list[696].m_Longitude = 126.71561111111112;

    OSVOM = &fix_list[697];
    fix_list[697].m_Latitude = 36.64555555555555;
    fix_list[697].m_Longitude = 129.39194444444445;

    OVGEN = &fix_list[698];
    fix_list[698].m_Latitude = 34.77283333333333;
    fix_list[698].m_Longitude = 126.1966388888889;

    OVLIN = &fix_list[699];
    fix_list[699].m_Latitude = 35.00138888888889;
    fix_list[699].m_Longitude = 128.7486111111111;

    OVTUS = &fix_list[700];
    fix_list[700].m_Latitude = 35.11119444444444;
    fix_list[700].m_Longitude = 128.65;

    OWING = &fix_list[701];
    fix_list[701].m_Latitude = 36.728835833333335;
    fix_list[701].m_Longitude = 127.24566694444445;

    P2 = &fix_list[702];
    fix_list[702].m_Latitude = 38;
    fix_list[702].m_Longitude = 124.33333333333333;

    PALDU = &fix_list[703];
    fix_list[703].m_Latitude = 37.97466527777778;
    fix_list[703].m_Longitude = 132.60668083333331;

    PALRI = &fix_list[704];
    fix_list[704].m_Latitude = 33.64088888888889;
    fix_list[704].m_Longitude = 126.74372222222222;

    PALSA = &fix_list[705];
    fix_list[705].m_Latitude = 34.025277777777774;
    fix_list[705].m_Longitude = 124.41472222222222;

    PAMBI = &fix_list[706];
    fix_list[706].m_Latitude = 37.18175;
    fix_list[706].m_Longitude = 126.54288888888888;

    PANSI = &fix_list[707];
    fix_list[707].m_Latitude = 33.003888333333336;
    fix_list[707].m_Longitude = 126.20694444444445;

    PAPLU = &fix_list[708];
    fix_list[708].m_Latitude = 33.57805555555556;
    fix_list[708].m_Longitude = 127.06027777777777;

    PAPTO = &fix_list[709];
    fix_list[709].m_Latitude = 35.98833333333334;
    fix_list[709].m_Longitude = 129.45808333333332;

    PC401 = &fix_list[710];
    fix_list[710].m_Latitude = 33.47347222222223;
    fix_list[710].m_Longitude = 126.41716666666667;

    PC621 = &fix_list[711];
    fix_list[711].m_Latitude = 33.740944444444445;
    fix_list[711].m_Longitude = 126.22469444444445;

    PC622 = &fix_list[712];
    fix_list[712].m_Latitude = 33.72955555555556;
    fix_list[712].m_Longitude = 126.12572222222222;

    PC623 = &fix_list[713];
    fix_list[713].m_Latitude = 33.6945;
    fix_list[713].m_Longitude = 126.03505555555556;

    PC624 = &fix_list[714];
    fix_list[714].m_Latitude = 33.63886111111111;
    fix_list[714].m_Longitude = 125.96061111111112;

    PC625 = &fix_list[715];
    fix_list[715].m_Latitude = 33.567527777777784;
    fix_list[715].m_Longitude = 125.90883333333333;

    PC626 = &fix_list[716];
    fix_list[716].m_Latitude = 33.48663888888889;
    fix_list[716].m_Longitude = 125.8841388888889;

    PC628 = &fix_list[717];
    fix_list[717].m_Latitude = 33.324555555555555;
    fix_list[717].m_Longitude = 125.92180555555557;

    PC721 = &fix_list[718];
    fix_list[718].m_Latitude = 33.91480555555555;
    fix_list[718].m_Longitude = 126.78602777777778;

    PC722 = &fix_list[719];
    fix_list[719].m_Latitude = 33.867472222222226;
    fix_list[719].m_Longitude = 126.63024999999999;

    PC723 = &fix_list[720];
    fix_list[720].m_Latitude = 33.59563888888889;
    fix_list[720].m_Longitude = 126.49497222222222;

    PC724 = &fix_list[721];
    fix_list[721].m_Latitude = 33.714444444444446;
    fix_list[721].m_Longitude = 126.42197222222222;

    PC725 = &fix_list[722];
    fix_list[722].m_Latitude = 33.32366666666667;
    fix_list[722].m_Longitude = 126.48247222222223;

    PC726 = &fix_list[723];
    fix_list[723].m_Latitude = 33.908944444444444;
    fix_list[723].m_Longitude = 126.49844444444444;

    PC727 = &fix_list[724];
    fix_list[724].m_Latitude = 33.406444444444446;
    fix_list[724].m_Longitude = 126.24969444444444;

    PC728 = &fix_list[725];
    fix_list[725].m_Latitude = 33.914944444444444;
    fix_list[725].m_Longitude = 127.09694444444445;

    PC735 = &fix_list[726];
    fix_list[726].m_Latitude = 33.556527777777774;
    fix_list[726].m_Longitude = 126.65855583333334;

    PC764 = &fix_list[727];
    fix_list[727].m_Latitude = 33.413944444444446;
    fix_list[727].m_Longitude = 126.86044444444444;

    PC761 = &fix_list[728];
    fix_list[728].m_Latitude = 33.98813888888889;
    fix_list[728].m_Longitude = 126.61016666666666;

    PC762 = &fix_list[729];
    fix_list[729].m_Latitude = 33.965805555555555;
    fix_list[729].m_Longitude = 126.81958333333333;

    PC763 = &fix_list[730];
    fix_list[730].m_Latitude = 34.05627777777777;
    fix_list[730].m_Longitude = 127.01211111111111;

    PC767 = &fix_list[731];
    fix_list[731].m_Latitude = 33.881255555555555;
    fix_list[731].m_Longitude = 126.85644444444443;

    VEKDI = &fix_list[732];
    fix_list[732].m_Latitude = 33.95627777777778;
    fix_list[732].m_Longitude = 126.91911111111112;

    DOKVU = &fix_list[733];
    fix_list[733].m_Latitude = 33.91383333333333;
    fix_list[733].m_Longitude = 127.00533333333334;

    KIBEK = &fix_list[734];
    fix_list[734].m_Latitude = 34.056305555555554;
    fix_list[734].m_Longitude = 126.61016666666666;

    PC682 = &fix_list[735];
    fix_list[735].m_Latitude = 33.85483333333333;
    fix_list[735].m_Longitude = 127.07616666666667;

    PC683 = &fix_list[736];
    fix_list[736].m_Latitude = 33.783;
    fix_list[736].m_Longitude = 127.12713888888888;

    PC684 = &fix_list[737];
    fix_list[737].m_Latitude = 33.70286111111111;
    fix_list[737].m_Longitude = 127.15508333333334;

    PC685 = &fix_list[738];
    fix_list[738].m_Latitude = 33.619416666666666;
    fix_list[738].m_Longitude = 127.15836111111112;

    LIDVO = &fix_list[739];
    fix_list[739].m_Latitude = 33.53788888888889;
    fix_list[739].m_Longitude = 127.13680555555557;

    PC765 = &fix_list[740];
    fix_list[740].m_Latitude = 33.538777777777774;
    fix_list[740].m_Longitude = 126.39516666666667;

    PC811 = &fix_list[741];
    fix_list[741].m_Latitude = 33.703361111111114;
    fix_list[741].m_Longitude = 126.71355555555556;

    PC813 = &fix_list[742];
    fix_list[742].m_Latitude = 33.49875;
    fix_list[742].m_Longitude = 126.84722222222221;

    PC814 = &fix_list[743];
    fix_list[743].m_Latitude = 33.26011111111111;
    fix_list[743].m_Longitude = 126.48708333333333;

    PC816 = &fix_list[744];
    fix_list[744].m_Latitude = 33.44902777777777;
    fix_list[744].m_Longitude = 126.32522222222222;

    PC832 = &fix_list[745];
    fix_list[745].m_Latitude = 33.679444999999994;
    fix_list[745].m_Longitude = 126.23108222222223;

    PC833 = &fix_list[746];
    fix_list[746].m_Latitude = 33.83577777777778;
    fix_list[746].m_Longitude = 126.51244472222223;

    PC834 = &fix_list[747];
    fix_list[747].m_Latitude = 33.9295;
    fix_list[747].m_Longitude = 126.6821388888889;

    PC841 = &fix_list[748];
    fix_list[748].m_Latitude = 33.428527777777774;
    fix_list[748].m_Longitude = 126.32994444444444;

    PC842 = &fix_list[749];
    fix_list[749].m_Latitude = 33.29397222222222;
    fix_list[749].m_Longitude = 126.35480555555554;

    PC845 = &fix_list[750];
    fix_list[750].m_Latitude = 33.41755555555555;
    fix_list[750].m_Longitude = 126.89;

    PC846 = &fix_list[751];
    fix_list[751].m_Latitude = 33.321000000000005;
    fix_list[751].m_Longitude = 126.59127777777778;

    PC861 = &fix_list[752];
    fix_list[752].m_Latitude = 33.56216666666666;
    fix_list[752].m_Longitude = 126.40947194444445;

    PC871 = &fix_list[753];
    fix_list[753].m_Latitude = 33.65147222222222;
    fix_list[753].m_Longitude = 126.4088888888889;

    PC872 = &fix_list[754];
    fix_list[754].m_Latitude = 33.721361111111115;
    fix_list[754].m_Longitude = 126.52186111111111;

    PC874 = &fix_list[755];
    fix_list[755].m_Latitude = 33.81055555555555;
    fix_list[755].m_Longitude = 127.18577777777779;

    PD501 = &fix_list[756];
    fix_list[756].m_Latitude = 33.232305555555556;
    fix_list[756].m_Longitude = 126.71244444444444;

    PD502 = &fix_list[757];
    fix_list[757].m_Latitude = 33.30169444444444;
    fix_list[757].m_Longitude = 126.71205555555557;

    PD701 = &fix_list[758];
    fix_list[758].m_Latitude = 33.38191694444445;
    fix_list[758].m_Longitude = 126.87013888888889;

    PD702 = &fix_list[759];
    fix_list[759].m_Latitude = 33.325388888888895;
    fix_list[759].m_Longitude = 126.980445;

    PD703 = &fix_list[760];
    fix_list[760].m_Latitude = 33.67344444444444;
    fix_list[760].m_Longitude = 127.29188888888889;

    PD704 = &fix_list[761];
    fix_list[761].m_Latitude = 33.569;
    fix_list[761].m_Longitude = 127.2775;

    PD705 = &fix_list[762];
    fix_list[762].m_Latitude = 33.420249999999996;
    fix_list[762].m_Longitude = 127.25711111111112;

    PD706 = &fix_list[763];
    fix_list[763].m_Latitude = 33.270805555555555;
    fix_list[763].m_Longitude = 127.1128611111111;

    PD801 = &fix_list[764];
    fix_list[764].m_Latitude = 33.43872194444444;
    fix_list[764].m_Longitude = 126.71130583333334;

    PD802 = &fix_list[765];
    fix_list[765].m_Latitude = 33.41641694444444;
    fix_list[765].m_Longitude = 126.83819472222221;

    PD803 = &fix_list[766];
    fix_list[766].m_Latitude = 33.340195;
    fix_list[766].m_Longitude = 126.88166694444443;

    PD804 = &fix_list[767];
    fix_list[767].m_Latitude = 33.276805833333334;
    fix_list[767].m_Longitude = 126.78347194444444;

    PD805 = &fix_list[768];
    fix_list[768].m_Latitude = 33.335861111111114;
    fix_list[768].m_Longitude = 126.85908333333333;

    PD806 = &fix_list[769];
    fix_list[769].m_Latitude = 33.37116666666667;
    fix_list[769].m_Longitude = 127.04341666666666;

    PD807 = &fix_list[770];
    fix_list[770].m_Latitude = 33.63952777777778;
    fix_list[770].m_Longitude = 127.23186111111112;

    PD808 = &fix_list[771];
    fix_list[771].m_Latitude = 33.31608333333333;
    fix_list[771].m_Longitude = 126.71197222222223;

    PD811 = &fix_list[772];
    fix_list[772].m_Latitude = 33.24341694444445;
    fix_list[772].m_Longitude = 126.71241694444444;

    PD812 = &fix_list[773];
    fix_list[773].m_Latitude = 33.20138888888889;
    fix_list[773].m_Longitude = 126.60483277777777;

    PD813 = &fix_list[774];
    fix_list[774].m_Latitude = 33.251221944444445;
    fix_list[774].m_Longitude = 126.52022194444444;

    PD814 = &fix_list[775];
    fix_list[775].m_Latitude = 33.337721944444446;
    fix_list[775].m_Longitude = 126.52925;

    PE029 = &fix_list[776];
    fix_list[776].m_Latitude = 37.10172222222222;
    fix_list[776].m_Longitude = 126.59075;

    PE048 = &fix_list[777];
    fix_list[777].m_Latitude = 37.21033333333334;
    fix_list[777].m_Longitude = 126.22463888888889;

    PE054 = &fix_list[778];
    fix_list[778].m_Latitude = 37.20852777777778;
    fix_list[778].m_Longitude = 126.09299999999999;

    PEBRI = &fix_list[779];
    fix_list[779].m_Latitude = 36.386388333333336;
    fix_list[779].m_Longitude = 127.00361111111111;

    PEDLO = &fix_list[780];
    fix_list[780].m_Latitude = 34.98975;
    fix_list[780].m_Longitude = 129.13758333333334;

    PEGMI = &fix_list[781];
    fix_list[781].m_Latitude = 35.226507777777776;
    fix_list[781].m_Longitude = 128.31406083333334;

    PEGRO = &fix_list[782];
    fix_list[782].m_Latitude = 34.76916666666666;
    fix_list[782].m_Longitude = 126.56725;

    PH002 = &fix_list[783];
    fix_list[783].m_Latitude = 37.50411111111111;
    fix_list[783].m_Longitude = 126.38769444444445;

    PH036 = &fix_list[784];
    fix_list[784].m_Latitude = 37.31155555555555;
    fix_list[784].m_Longitude = 125.91372222222223;

    PH037 = &fix_list[785];
    fix_list[785].m_Latitude = 37.231750000000005;
    fix_list[785].m_Longitude = 126.03755555555556;

    PIBAK = &fix_list[786];
    fix_list[786].m_Latitude = 37.30616666666666;
    fix_list[786].m_Longitude = 126.5978611111111;

    PIKAR = &fix_list[787];
    fix_list[787].m_Latitude = 37.509166666666665;
    fix_list[787].m_Longitude = 126.41277777777778;

    PILIT = &fix_list[788];
    fix_list[788].m_Latitude = 37.439273611111105;
    fix_list[788].m_Longitude = 129.294485;

    PIMIK = &fix_list[789];
    fix_list[789].m_Latitude = 33.257333333333335;
    fix_list[789].m_Longitude = 125.98075;

    PINAS = &fix_list[790];
    fix_list[790].m_Latitude = 34.57002777777778;
    fix_list[790].m_Longitude = 126.75027777777778;

    PINEV = &fix_list[791];
    fix_list[791].m_Latitude = 37.25277777777778;
    fix_list[791].m_Longitude = 127.31777777777778;

    PIPAN = &fix_list[792];
    fix_list[792].m_Latitude = 37.379194444444444;
    fix_list[792].m_Longitude = 126.49877777777778;

    PK513 = &fix_list[793];
    fix_list[793].m_Latitude = 34.90897222222222;
    fix_list[793].m_Longitude = 129.03327777777778;

    PK514 = &fix_list[794];
    fix_list[794].m_Latitude = 34.978972222222225;
    fix_list[794].m_Longitude = 129.1395;

    PK521 = &fix_list[795];
    fix_list[795].m_Latitude = 35.22833333333333;
    fix_list[795].m_Longitude = 128.64227777777776;

    PK522 = &fix_list[796];
    fix_list[796].m_Latitude = 35.125083333333336;
    fix_list[796].m_Longitude = 128.7468333333333;

    PK711 = &fix_list[797];
    fix_list[797].m_Latitude = 34.96441666666667;
    fix_list[797].m_Longitude = 128.84230555555555;

    PK712 = &fix_list[798];
    fix_list[798].m_Latitude = 35.10988888888889;
    fix_list[798].m_Longitude = 128.94827777777778;

    PK722 = &fix_list[799];
    fix_list[799].m_Latitude = 35.10586111111111;
    fix_list[799].m_Longitude = 128.9464722222222;

    PK731 = &fix_list[800];
    fix_list[800].m_Latitude = 35.067972222222224;
    fix_list[800].m_Longitude = 128.8131111111111;

    POLEG = &fix_list[801];
    fix_list[801].m_Latitude = 37.21329027777778;
    fix_list[801].m_Longitude = 126.9913425;

    POMIM = &fix_list[802];
    fix_list[802].m_Latitude = 37.289944444444444;
    fix_list[802].m_Longitude = 126.13947222222222;

    POMOX = &fix_list[803];
    fix_list[803].m_Latitude = 35.14155;
    fix_list[803].m_Longitude = 128.25121694444445;

    PONIK = &fix_list[804];
    fix_list[804].m_Latitude = 32.005833333333335;
    fix_list[804].m_Longitude = 125.783055;

    PONIL = &fix_list[805];
    fix_list[805].m_Latitude = 38.85;
    fix_list[805].m_Longitude = 124.24666666666667;

    PORIX = &fix_list[806];
    fix_list[806].m_Latitude = 35.68263888888889;
    fix_list[806].m_Longitude = 126.76144444444445;

    POSAN = &fix_list[807];
    fix_list[807].m_Latitude = 36.937352499999996;
    fix_list[807].m_Longitude = 127.22152472222223;

    POSCO = &fix_list[808];
    fix_list[808].m_Latitude = 36.1327775;
    fix_list[808].m_Longitude = 129.27222194444445;

    POSEP = &fix_list[809];
    fix_list[809].m_Latitude = 37.472722222222224;
    fix_list[809].m_Longitude = 126.22277777777778;

    POSOK = &fix_list[810];
    fix_list[810].m_Latitude = 37.24175;
    fix_list[810].m_Longitude = 126.64905555555556;

    POTET = &fix_list[811];
    fix_list[811].m_Latitude = 32.27996944444445;
    fix_list[811].m_Longitude = 127.03965972222223;

    POVEM = &fix_list[812];
    fix_list[812].m_Latitude = 34.92305555555555;
    fix_list[812].m_Longitude = 128.90444444444444;

    POVOR = &fix_list[813];
    fix_list[813].m_Latitude = 34.25555555555555;
    fix_list[813].m_Longitude = 127.73333333333333;

    PQ032 = &fix_list[814];
    fix_list[814].m_Latitude = 37.15486111111111;
    fix_list[814].m_Longitude = 127.07974999999999;

    PQ058 = &fix_list[815];
    fix_list[815].m_Latitude = 37.03297222222222;
    fix_list[815].m_Longitude = 126.53175;

    PQ070 = &fix_list[816];
    fix_list[816].m_Latitude = 37.142833333333336;
    fix_list[816].m_Longitude = 126.23972222222223;

    PQ078 = &fix_list[817];
    fix_list[817].m_Latitude = 37.14122222222222;
    fix_list[817].m_Longitude = 126.06594444444444;

    PQ091 = &fix_list[818];
    fix_list[818].m_Latitude = 37.138305555555554;
    fix_list[818].m_Longitude = 125.80127777777777;

    PT017 = &fix_list[819];
    fix_list[819].m_Latitude = 37.341861111111115;
    fix_list[819].m_Longitude = 126.91408333333334;

    SUNEM = &fix_list[820];
    fix_list[820].m_Latitude = 37.2835;
    fix_list[820].m_Longitude = 126.83941666666666;

    PT029 = &fix_list[821];
    fix_list[821].m_Latitude = 37.23352777777778;
    fix_list[821].m_Longitude = 126.7055;

    PT030 = &fix_list[822];
    fix_list[822].m_Latitude = 37.17772222222222;
    fix_list[822].m_Longitude = 127.12394444444443;

    PT041 = &fix_list[823];
    fix_list[823].m_Latitude = 37.06680555555556;
    fix_list[823].m_Longitude = 126.91000000000001;

    PT042 = &fix_list[824];
    fix_list[824].m_Latitude = 37.144527777777775;
    fix_list[824].m_Longitude = 126.46852777777778;

    PT054 = &fix_list[825];
    fix_list[825].m_Latitude = 37.07633333333334;
    fix_list[825].m_Longitude = 126.24838888888888;

    PT055 = &fix_list[826];
    fix_list[826].m_Latitude = 37.14502777777778;
    fix_list[826].m_Longitude = 126.54980555555555;

    PT062 = &fix_list[827];
    fix_list[827].m_Latitude = 37.14413888888889;
    fix_list[827].m_Longitude = 126.41038888888889;

    PT075 = &fix_list[828];
    fix_list[828].m_Latitude = 37.071555555555555;
    fix_list[828].m_Longitude = 125.79730555555555;

    PT091 = &fix_list[829];
    fix_list[829].m_Latitude = 37.138305555555554;
    fix_list[829].m_Longitude = 125.80127777777777;

    PU025 = &fix_list[830];
    fix_list[830].m_Latitude = 37.57752777777778;
    fix_list[830].m_Longitude = 126.34508333333333;

    PU029 = &fix_list[831];
    fix_list[831].m_Latitude = 37.45280555555556;
    fix_list[831].m_Longitude = 126.33675;

    PU033 = &fix_list[832];
    fix_list[832].m_Latitude = 37.54055555555556;
    fix_list[832].m_Longitude = 126.18444444444445;

    PU044 = &fix_list[833];
    fix_list[833].m_Latitude = 37.27913888888889;
    fix_list[833].m_Longitude = 126.09252777777778;

    PU046 = &fix_list[834];
    fix_list[834].m_Latitude = 37.42838888888889;
    fix_list[834].m_Longitude = 125.9525;

    PU060 = &fix_list[835];
    fix_list[835].m_Latitude = 37.3035;
    fix_list[835].m_Longitude = 125.6961388888889;

    PU063 = &fix_list[836];
    fix_list[836].m_Latitude = 37.071555555555555;
    fix_list[836].m_Longitude = 125.79730555555555;

    PU402 = &fix_list[837];
    fix_list[837].m_Latitude = 35.73727777777778;
    fix_list[837].m_Longitude = 129.30594444444446;

    PU403 = &fix_list[838];
    fix_list[838].m_Latitude = 35.65430555555555;
    fix_list[838].m_Longitude = 129.3348888888889;

    PU501 = &fix_list[839];
    fix_list[839].m_Latitude = 35.43836111111111;
    fix_list[839].m_Longitude = 129.48413888888888;

    PU701 = &fix_list[840];
    fix_list[840].m_Latitude = 35.57911083333334;
    fix_list[840].m_Longitude = 129.40980583333334;

    PU751 = &fix_list[841];
    fix_list[841].m_Latitude = 35.78705583333333;
    fix_list[841].m_Longitude = 129.4128327777778;

    PU752 = &fix_list[842];
    fix_list[842].m_Latitude = 35.899055833333335;
    fix_list[842].m_Longitude = 129.37197194444445;

    PU801 = &fix_list[843];
    fix_list[843].m_Latitude = 35.635777777777776;
    fix_list[843].m_Longitude = 129.348195;

    PU802 = &fix_list[844];
    fix_list[844].m_Latitude = 35.830110833333336;
    fix_list[844].m_Longitude = 129.2523888888889;

    PU803 = &fix_list[845];
    fix_list[845].m_Latitude = 35.71274972222223;
    fix_list[845].m_Longitude = 129.32630583333332;

    PU851 = &fix_list[846];
    fix_list[846].m_Latitude = 35.533138888888885;
    fix_list[846].m_Longitude = 129.37002777777778;

    PU852 = &fix_list[847];
    fix_list[847].m_Latitude = 35.614221944444445;
    fix_list[847].m_Longitude = 129.2713327777778;

    PU853 = &fix_list[848];
    fix_list[848].m_Latitude = 35.69127777777778;
    fix_list[848].m_Longitude = 129.31430583333335;

    PUDEN = &fix_list[849];
    fix_list[849].m_Latitude = 36.07666666666667;
    fix_list[849].m_Longitude = 129.40986111111113;

    PUDIM = &fix_list[850];
    fix_list[850].m_Latitude = 37.63172222222222;
    fix_list[850].m_Longitude = 126.30833333333334;

    PUDUB = &fix_list[851];
    fix_list[851].m_Latitude = 37.340694722222224;
    fix_list[851].m_Longitude = 127.06016694444445;

    PY019 = &fix_list[852];
    fix_list[852].m_Latitude = 37.189;
    fix_list[852].m_Longitude = 126.667;

    PY031 = &fix_list[853];
    fix_list[853].m_Latitude = 37.094750000000005;
    fix_list[853].m_Longitude = 126.24997222222223;

    PY036 = &fix_list[854];
    fix_list[854].m_Latitude = 37.0925;
    fix_list[854].m_Longitude = 126.01722222222222;

    PY049 = &fix_list[855];
    fix_list[855].m_Latitude = 37.111444444444444;
    fix_list[855].m_Longitude = 125.80177777777777;

    PY421 = &fix_list[856];
    fix_list[856].m_Latitude = 39.13909388888889;
    fix_list[856].m_Longitude = 125.69640611111112;

    PY422 = &fix_list[857];
    fix_list[857].m_Latitude = 39.083266944444446;
    fix_list[857].m_Longitude = 125.71834694444445;

    PY423 = &fix_list[858];
    fix_list[858].m_Latitude = 39.058793888888886;
    fix_list[858].m_Longitude = 125.61605305555555;

    PY426 = &fix_list[859];
    fix_list[859].m_Latitude = 39.288888888888884;
    fix_list[859].m_Longitude = 125.88333305555555;

    PY431 = &fix_list[860];
    fix_list[860].m_Latitude = 39.296928055555554;
    fix_list[860].m_Longitude = 125.63424388888889;

    PY432 = &fix_list[861];
    fix_list[861].m_Latitude = 39.35275;
    fix_list[861].m_Longitude = 125.61221888888889;

    PY433 = &fix_list[862];
    fix_list[862].m_Latitude = 39.37714694444445;
    fix_list[862].m_Longitude = 125.71496888888889;

    PY434 = &fix_list[863];
    fix_list[863].m_Latitude = 39.32827805555556;
    fix_list[863].m_Longitude = 125.50953305555555;

    PY435 = &fix_list[864];
    fix_list[864].m_Latitude = 39.432493888888885;
    fix_list[864].m_Longitude = 125.58071888888888;

    PY521 = &fix_list[865];
    fix_list[865].m_Latitude = 39.20872222222223;
    fix_list[865].m_Longitude = 125.51116666666667;

    PY531 = &fix_list[866];
    fix_list[866].m_Latitude = 39.29152777777777;
    fix_list[866].m_Longitude = 125.86038888888888;

    PY621 = &fix_list[867];
    fix_list[867].m_Latitude = 39.22777777777778;
    fix_list[867].m_Longitude = 125.55277777777778;

    PY622 = &fix_list[868];
    fix_list[868].m_Latitude = 39.361111111111114;
    fix_list[868].m_Longitude = 125.52777777777777;

    PZ026 = &fix_list[869];
    fix_list[869].m_Latitude = 37.42825;
    fix_list[869].m_Longitude = 126.62969444444444;

    PZ030 = &fix_list[870];
    fix_list[870].m_Latitude = 37.35413888888889;
    fix_list[870].m_Longitude = 126.54077777777778;

    PZ035 = &fix_list[871];
    fix_list[871].m_Latitude = 37.27286111111111;
    fix_list[871].m_Longitude = 126.44355555555556;

    PZ040 = &fix_list[872];
    fix_list[872].m_Latitude = 37.1795;
    fix_list[872].m_Longitude = 126.33219444444444;

    PZ049 = &fix_list[873];
    fix_list[873].m_Latitude = 37.14113888888889;
    fix_list[873].m_Longitude = 126.057;

    PZ061 = &fix_list[874];
    fix_list[874].m_Latitude = 37.138305555555554;
    fix_list[874].m_Longitude = 125.80127777777777;

    QD040 = &fix_list[875];
    fix_list[875].m_Latitude = 37.634166666666665;
    fix_list[875].m_Longitude = 126.69269444444444;

    QD050 = &fix_list[876];
    fix_list[876].m_Latitude = 37.561416666666666;
    fix_list[876].m_Longitude = 126.59363888888889;

    QD080 = &fix_list[877];
    fix_list[877].m_Latitude = 37.47813888888889;
    fix_list[877].m_Longitude = 126.58997222222222;

    QD090 = &fix_list[878];
    fix_list[878].m_Latitude = 37.37177777777778;
    fix_list[878].m_Longitude = 126.58527777777778;

    QD110 = &fix_list[879];
    fix_list[879].m_Latitude = 37.27119444444445;
    fix_list[879].m_Longitude = 126.62883333333333;

    QD150 = &fix_list[880];
    fix_list[880].m_Latitude = 37.044333333333334;
    fix_list[880].m_Longitude = 126.8146111111111;

    QD160 = &fix_list[881];
    fix_list[881].m_Latitude = 36.889694444444444;
    fix_list[881].m_Longitude = 126.81958333333333;

    QG180 = &fix_list[882];
    fix_list[882].m_Latitude = 36.92477777777778;
    fix_list[882].m_Longitude = 127.16211111111112;

    QK080 = &fix_list[883];
    fix_list[883].m_Latitude = 37.41255555555556;
    fix_list[883].m_Longitude = 126.6658888888889;

    QP079 = &fix_list[884];
    fix_list[884].m_Latitude = 37.48447222222222;
    fix_list[884].m_Longitude = 126.44575;

    QP080 = &fix_list[885];
    fix_list[885].m_Latitude = 37.52158333333333;
    fix_list[885].m_Longitude = 126.53952777777778;

    QP120 = &fix_list[886];
    fix_list[886].m_Latitude = 37.40986111111111;
    fix_list[886].m_Longitude = 126.2581388888889;

    REBIT = &fix_list[887];
    fix_list[887].m_Latitude = 37.200832222222225;
    fix_list[887].m_Longitude = 125.48686083333334;

    RELEX = &fix_list[888];
    fix_list[888].m_Latitude = 34.71977777777778;
    fix_list[888].m_Longitude = 126.38452777777779;

    REMOS = &fix_list[889];
    fix_list[889].m_Latitude = 33.43472222222222;
    fix_list[889].m_Longitude = 126.3913888888889;

    RENEK = &fix_list[890];
    fix_list[890].m_Latitude = 33.56072222222222;
    fix_list[890].m_Longitude = 126.58697222222222;

    RETAG = &fix_list[891];
    fix_list[891].m_Latitude = 35.92372222222222;
    fix_list[891].m_Longitude = 126.61108333333333;

    RILRO = &fix_list[892];
    fix_list[892].m_Latitude = 37.17583333333333;
    fix_list[892].m_Longitude = 124.245;

    RIMPO = &fix_list[893];
    fix_list[893].m_Latitude = 35.1275;
    fix_list[893].m_Longitude = 127.58388888888888;

    RIMTA = &fix_list[894];
    fix_list[894].m_Latitude = 35.64511111111111;
    fix_list[894].m_Longitude = 129.34741666666667;

    RINBO = &fix_list[895];
    fix_list[895].m_Latitude = 35.897888611111114;
    fix_list[895].m_Longitude = 126.8968888888889;

    RITEK = &fix_list[896];
    fix_list[896].m_Latitude = 42.26499166666667;
    fix_list[896].m_Longitude = 131.73973611111109;

    ROCEE = &fix_list[897];
    fix_list[897].m_Latitude = 35.81922222222222;
    fix_list[897].m_Longitude = 126.63597222222224;

    GUMAM = &fix_list[898];
    fix_list[898].m_Latitude = 35.366416666666666;
    fix_list[898].m_Longitude = 127.42602777777778;

    RUMRI = &fix_list[899];
    fix_list[899].m_Latitude = 37.53691666666666;
    fix_list[899].m_Longitude = 126.35844444444444;

    RUNIT = &fix_list[900];
    fix_list[900].m_Latitude = 35.126111111111115;
    fix_list[900].m_Longitude = 128.49777777777777;

    RUNSA = &fix_list[901];
    fix_list[901].m_Latitude = 35.98513888888889;
    fix_list[901].m_Longitude = 129.1838888888889;

    RUTON = &fix_list[902];
    fix_list[902].m_Latitude = 36.14055555555556;
    fix_list[902].m_Longitude = 129.53194444444446;

    RUVIS = &fix_list[903];
    fix_list[903].m_Latitude = 35.98677777777778;
    fix_list[903].m_Longitude = 129.31658333333334;

    SABET = &fix_list[904];
    fix_list[904].m_Latitude = 37.64138888888889;
    fix_list[904].m_Longitude = 132.67194444444445;

    SABUM = &fix_list[905];
    fix_list[905].m_Latitude = 35.99005555555556;
    fix_list[905].m_Longitude = 129.63477777777777;

    SACUN = &fix_list[906];
    fix_list[906].m_Latitude = 35.107505833333335;
    fix_list[906].m_Longitude = 128.11515777777777;

    SADLI = &fix_list[907];
    fix_list[907].m_Latitude = 31.83;
    fix_list[907].m_Longitude = 125;

    SAKOS = &fix_list[908];
    fix_list[908].m_Latitude = 37.589555555555556;
    fix_list[908].m_Longitude = 126.34602777777778;

    SAKYU = &fix_list[909];
    fix_list[909].m_Latitude = 35.91786666666666;
    fix_list[909].m_Longitude = 134.64788583333333;

    SALMI = &fix_list[910];
    fix_list[910].m_Latitude = 28.315;
    fix_list[910].m_Longitude = 124;

    SAMLO = &fix_list[911];
    fix_list[911].m_Latitude = 32.53668083333333;
    fix_list[911].m_Longitude = 126.26325416666667;

    SAMON = &fix_list[912];
    fix_list[912].m_Latitude = 36.24285555555556;
    fix_list[912].m_Longitude = 134.5033388888889;

    SAMUL = &fix_list[913];
    fix_list[913].m_Latitude = 35.12266666666667;
    fix_list[913].m_Longitude = 126.85899972222222;

    SANKO = &fix_list[914];
    fix_list[914].m_Latitude = 38.24995194444445;
    fix_list[914].m_Longitude = 122.45331444444444;

    MEVIM = &fix_list[915];
    fix_list[915].m_Latitude = 35.82188888888889;
    fix_list[915].m_Longitude = 128.79033333333334;

    SANLA = &fix_list[916];
    fix_list[916].m_Latitude = 37.22763888888889;
    fix_list[916].m_Longitude = 126.34416666666667;

    SAPDI = &fix_list[917];
    fix_list[917].m_Latitude = 35.12283277777778;
    fix_list[917].m_Longitude = 128.4919997222222;

    SAPUX = &fix_list[918];
    fix_list[918].m_Latitude = 37.54857916666666;
    fix_list[918].m_Longitude = 127.36745138888888;

    SARAM = &fix_list[919];
    fix_list[919].m_Latitude = 35.12266666666667;
    fix_list[919].m_Longitude = 128.52449972222223;

    SASRI = &fix_list[920];
    fix_list[920].m_Latitude = 39.02611111111111;
    fix_list[920].m_Longitude = 125.39472222222223;

    SEDMO = &fix_list[921];
    fix_list[921].m_Latitude = 35.80752777777777;
    fix_list[921].m_Longitude = 129.28194444444446;

    SEGBO = &fix_list[922];
    fix_list[922].m_Latitude = 37.522777777777776;
    fix_list[922].m_Longitude = 126.36666666666666;

    SEHEE = &fix_list[923];
    fix_list[923].m_Latitude = 34.743611111111115;
    fix_list[923].m_Longitude = 127.51083333333334;

    SELPA = &fix_list[924];
    fix_list[924].m_Latitude = 37.920833333333334;
    fix_list[924].m_Longitude = 130.81972222222223;

    SEPCO = &fix_list[925];
    fix_list[925].m_Latitude = 38.93215277777777;
    fix_list[925].m_Longitude = 137.12963583333334;

    LUVOL = &fix_list[926];
    fix_list[926].m_Latitude = 35.479305555555555;
    fix_list[926].m_Longitude = 126.94741666666667;

    ONUGO = &fix_list[927];
    fix_list[927].m_Latitude = 35.82094444444445;
    fix_list[927].m_Longitude = 128.78952777777778;

    SKOTA = &fix_list[928];
    fix_list[928].m_Latitude = 35.10136111111111;
    fix_list[928].m_Longitude = 127.49005555555556;

    SLOTA = &fix_list[929];
    fix_list[929].m_Latitude = 35.207705833333335;
    fix_list[929].m_Longitude = 128.2804438888889;

    SOCHA = &fix_list[930];
    fix_list[930].m_Latitude = 39.25;
    fix_list[930].m_Longitude = 126.21666666666667;

    SOKGE = &fix_list[931];
    fix_list[931].m_Latitude = 39.73166666666667;
    fix_list[931].m_Longitude = 125.68333333333334;

    SOMSA = &fix_list[932];
    fix_list[932].m_Latitude = 33.71833277777778;
    fix_list[932].m_Longitude = 121.64833277777778;

    SONDO = &fix_list[933];
    fix_list[933].m_Latitude = 39.72277777777778;
    fix_list[933].m_Longitude = 127.47055555555556;

    SOONA = &fix_list[934];
    fix_list[934].m_Latitude = 34.640971944444445;
    fix_list[934].m_Longitude = 127.71555583333334;

    SOONI = &fix_list[935];
    fix_list[935].m_Latitude = 35.155005833333334;
    fix_list[935].m_Longitude = 128.1863938888889;

    SOORO = &fix_list[936];
    fix_list[936].m_Latitude = 35.291666666666664;
    fix_list[936].m_Longitude = 128.7188888888889;

    BEVSI = &fix_list[937];
    fix_list[937].m_Latitude = 35.306666666666665;
    fix_list[937].m_Longitude = 128.72944444444445;

    SOSDO = &fix_list[938];
    fix_list[938].m_Latitude = 33.00333277777778;
    fix_list[938].m_Longitude = 126.45972166666667;

    STOUT = &fix_list[939];
    fix_list[939].m_Latitude = 34.19071083333333;
    fix_list[939].m_Longitude = 131.01618888888888;

    SUBTA = &fix_list[940];
    fix_list[940].m_Latitude = 28.9525;
    fix_list[940].m_Longitude = 124.50944444444444;

    SUBUK = &fix_list[941];
    fix_list[941].m_Latitude = 40.132686944444444;
    fix_list[941].m_Longitude = 131.41362666666666;

    SUPOM = &fix_list[942];
    fix_list[942].m_Latitude = 37.362972222222226;
    fix_list[942].m_Longitude = 127.20477777777778;

    SUPUL = &fix_list[943];
    fix_list[943].m_Latitude = 33.42972222222222;
    fix_list[943].m_Longitude = 126.92888888888889;

    SURAK = &fix_list[944];
    fix_list[944].m_Latitude = 31.781166388888888;
    fix_list[944].m_Longitude = 123.4815;

    SURAX = &fix_list[945];
    fix_list[945].m_Latitude = 36.733472222222225;
    fix_list[945].m_Longitude = 127.52461111111111;

    SURSO = &fix_list[946];
    fix_list[946].m_Latitude = 36.73522222222223;
    fix_list[946].m_Longitude = 127.26694444444445;

    TAMNA = &fix_list[947];
    fix_list[947].m_Latitude = 33.47097138888889;
    fix_list[947].m_Longitude = 127.33138888888888;

    TASUR = &fix_list[948];
    fix_list[948].m_Latitude = 37.629555555555555;
    fix_list[948].m_Longitude = 126.30449999999999;

    TAXUK = &fix_list[949];
    fix_list[949].m_Latitude = 38.144796944444444;
    fix_list[949].m_Longitude = 136.5626638888889;

    TD040 = &fix_list[950];
    fix_list[950].m_Latitude = 37.634166666666665;
    fix_list[950].m_Longitude = 126.69269444444444;

    TD050 = &fix_list[951];
    fix_list[951].m_Latitude = 37.561416666666666;
    fix_list[951].m_Longitude = 126.59363888888889;

    TD100 = &fix_list[952];
    fix_list[952].m_Latitude = 37.40522222222222;
    fix_list[952].m_Longitude = 126.57255555555555;

    TD120 = &fix_list[953];
    fix_list[953].m_Latitude = 37.32355555555556;
    fix_list[953].m_Longitude = 126.59463888888888;

    TD130 = &fix_list[954];
    fix_list[954].m_Latitude = 37.222388888888894;
    fix_list[954].m_Longitude = 126.62802777777777;

    TD180 = &fix_list[955];
    fix_list[955].m_Latitude = 37.01761111111111;
    fix_list[955].m_Longitude = 126.71197222222223;

    TD200 = &fix_list[956];
    fix_list[956].m_Latitude = 36.902388888888886;
    fix_list[956].m_Longitude = 126.73313888888889;

    TEBEX = &fix_list[957];
    fix_list[957].m_Latitude = 36.561388888888885;
    fix_list[957].m_Longitude = 127.99138888888889;

    TEDAN = &fix_list[958];
    fix_list[958].m_Latitude = 35.124;
    fix_list[958].m_Longitude = 127.30866666666667;

    TENAS = &fix_list[959];
    fix_list[959].m_Latitude = 37.63888861111111;
    fix_list[959].m_Longitude = 131.5741663888889;

    TENUL = &fix_list[960];
    fix_list[960].m_Latitude = 33.23377777777778;
    fix_list[960].m_Longitude = 126.91908333333333;

    TERNI = &fix_list[961];
    fix_list[961].m_Latitude = 42.37027777777778;
    fix_list[961].m_Longitude = 131.6674997222222;

    TESIK = &fix_list[962];
    fix_list[962].m_Latitude = 37.271277777777776;
    fix_list[962].m_Longitude = 126.90958333333334;

    TESIM = &fix_list[963];
    fix_list[963].m_Latitude = 31.590435277777775;
    fix_list[963].m_Longitude = 125.86235527777777;

    TEWOO = &fix_list[964];
    fix_list[964].m_Latitude = 33.45425;
    fix_list[964].m_Longitude = 126.37986111111111;

    TH501 = &fix_list[965];
    fix_list[965].m_Latitude = 36.077222222222225;
    fix_list[965].m_Longitude = 129.1821111111111;

    TH503 = &fix_list[966];
    fix_list[966].m_Latitude = 35.98597222222222;
    fix_list[966].m_Longitude = 129.2496111111111;

    TH505 = &fix_list[967];
    fix_list[967].m_Latitude = 35.98708333333333;
    fix_list[967].m_Longitude = 129.3431111111111;

    TH701 = &fix_list[968];
    fix_list[968].m_Latitude = 36.08883333333333;
    fix_list[968].m_Longitude = 129.63341666666665;

    TH702 = &fix_list[969];
    fix_list[969].m_Latitude = 35.891305555555554;
    fix_list[969].m_Longitude = 129.6361388888889;

    TH801 = &fix_list[970];
    fix_list[970].m_Latitude = 36.10630555555556;
    fix_list[970].m_Longitude = 129.5640277777778;

    TH802 = &fix_list[971];
    fix_list[971].m_Latitude = 36.128055555555555;
    fix_list[971].m_Longitude = 129.42249999999999;

    TH803 = &fix_list[972];
    fix_list[972].m_Latitude = 36.17122222222222;
    fix_list[972].m_Longitude = 129.13805555555555;

    TH804 = &fix_list[973];
    fix_list[973].m_Latitude = 35.95430555555556;
    fix_list[973].m_Longitude = 129.67024999999998;

    TH805 = &fix_list[974];
    fix_list[974].m_Latitude = 35.87255555555556;
    fix_list[974].m_Longitude = 129.56741666666667;

    TH806 = &fix_list[975];
    fix_list[975].m_Latitude = 35.870333333333335;
    fix_list[975].m_Longitude = 129.3798888888889;

    TH901 = &fix_list[976];
    fix_list[976].m_Latitude = 36.103388888888894;
    fix_list[976].m_Longitude = 129.29347222222222;

    TH902 = &fix_list[977];
    fix_list[977].m_Latitude = 36.247305555555556;
    fix_list[977].m_Longitude = 129.44127777777777;

    TH903 = &fix_list[978];
    fix_list[978].m_Latitude = 36.12938888888889;
    fix_list[978].m_Longitude = 129.2108888888889;

    TH904 = &fix_list[979];
    fix_list[979].m_Latitude = 35.86966666666667;
    fix_list[979].m_Longitude = 129.29766666666666;

    TH905 = &fix_list[980];
    fix_list[980].m_Latitude = 35.87116666666667;
    fix_list[980].m_Longitude = 129.43099999999998;

    TH906 = &fix_list[981];
    fix_list[981].m_Latitude = 35.96491666666667;
    fix_list[981].m_Longitude = 129.57883333333334;

    PIGEL = &fix_list[982];
    fix_list[982].m_Latitude = 35.02911111111111;
    fix_list[982].m_Longitude = 126.73972222222223;

    TIQUE = &fix_list[983];
    fix_list[983].m_Latitude = 34.687416666666664;
    fix_list[983].m_Longitude = 127.69291666666668;

    TK130 = &fix_list[984];
    fix_list[984].m_Latitude = 37.36830555555556;
    fix_list[984].m_Longitude = 126.85;

    TL001 = &fix_list[985];
    fix_list[985].m_Latitude = 37.02954972222222;
    fix_list[985].m_Longitude = 129.36838694444444;

    TL002 = &fix_list[986];
    fix_list[986].m_Latitude = 36.93874972222222;
    fix_list[986].m_Longitude = 129.4866236111111;

    TL003 = &fix_list[987];
    fix_list[987].m_Latitude = 36.881077777777776;
    fix_list[987].m_Longitude = 129.56500583333334;

    TL004 = &fix_list[988];
    fix_list[988].m_Latitude = 36.816534999999995;
    fix_list[988].m_Longitude = 129.64638027777778;

    TL011 = &fix_list[989];
    fix_list[989].m_Latitude = 36.350299722222225;
    fix_list[989].m_Longitude = 129.44194555555555;

    TL012 = &fix_list[990];
    fix_list[990].m_Latitude = 36.46051444444445;
    fix_list[990].m_Longitude = 129.52242944444447;

    TL013 = &fix_list[991];
    fix_list[991].m_Latitude = 36.64773805555556;
    fix_list[991].m_Longitude = 129.5194402777778;

    TL024 = &fix_list[992];
    fix_list[992].m_Latitude = 36.86185833333334;
    fix_list[992].m_Longitude = 129.4907372222222;

    TL025 = &fix_list[993];
    fix_list[993].m_Latitude = 36.93716166666666;
    fix_list[993].m_Longitude = 129.37795444444444;

    TL026 = &fix_list[994];
    fix_list[994].m_Latitude = 36.53370555555556;
    fix_list[994].m_Longitude = 129.40497305555556;

    TL034 = &fix_list[995];
    fix_list[995].m_Latitude = 36.720565;
    fix_list[995].m_Longitude = 129.5200027777778;

    TL035 = &fix_list[996];
    fix_list[996].m_Latitude = 36.561076666666665;
    fix_list[996].m_Longitude = 129.42220833333332;

    TL041 = &fix_list[997];
    fix_list[997].m_Latitude = 36.96886111111111;
    fix_list[997].m_Longitude = 129.49624999999997;

    TL043 = &fix_list[998];
    fix_list[998].m_Latitude = 36.86280555555556;
    fix_list[998].m_Longitude = 129.42852777777776;

    TL051 = &fix_list[999];
    fix_list[999].m_Latitude = 36.62522222222222;
    fix_list[999].m_Longitude = 129.62252777777778;

    TL053 = &fix_list[1000];
    fix_list[1000].m_Latitude = 36.68958333333333;
    fix_list[1000].m_Longitude = 129.49558333333331;

    TL121 = &fix_list[1001];
    fix_list[1001].m_Latitude = 36.6752325;
    fix_list[1001].m_Longitude = 129.49605027777775;

    TL222 = &fix_list[1002];
    fix_list[1002].m_Latitude = 36.68577777777777;
    fix_list[1002].m_Longitude = 129.58383333333333;

    TL223 = &fix_list[1003];
    fix_list[1003].m_Latitude = 36.78369444444444;
    fix_list[1003].m_Longitude = 129.54611111111112;

    TL131 = &fix_list[1004];
    fix_list[1004].m_Latitude = 36.88180138888889;
    fix_list[1004].m_Longitude = 129.4272147222222;

    TL232 = &fix_list[1005];
    fix_list[1005].m_Latitude = 36.90880555555555;
    fix_list[1005].m_Longitude = 129.49775;

    TL233 = &fix_list[1006];
    fix_list[1006].m_Latitude = 36.82855555555556;
    fix_list[1006].m_Longitude = 129.5287777777778;

    TODAL = &fix_list[1007];
    fix_list[1007].m_Latitude = 33.491;
    fix_list[1007].m_Longitude = 126.76497222222223;

    TOKIN = &fix_list[1008];
    fix_list[1008].m_Latitude = 33.60608333333334;
    fix_list[1008].m_Longitude = 126.67561111111111;

    TOLIS = &fix_list[1009];
    fix_list[1009].m_Latitude = 33.84166666666667;
    fix_list[1009].m_Longitude = 124.41472222222222;

    TONIN = &fix_list[1010];
    fix_list[1010].m_Latitude = 39.333333333333336;
    fix_list[1010].m_Longitude = 133;

    TONIX = &fix_list[1011];
    fix_list[1011].m_Latitude = 31.337999999999997;
    fix_list[1011].m_Longitude = 123.53283305555556;

    TOPAX = &fix_list[1012];
    fix_list[1012].m_Latitude = 34.76578055555556;
    fix_list[1012].m_Longitude = 128.49773499999998;

    TOREN = &fix_list[1013];
    fix_list[1013].m_Latitude = 33.81022222222222;
    fix_list[1013].m_Longitude = 126.66602777777778;

    TORUS = &fix_list[1014];
    fix_list[1014].m_Latitude = 37.606944444444444;
    fix_list[1014].m_Longitude = 128.13527777777776;

    TOSAN = &fix_list[1015];
    fix_list[1015].m_Latitude = 33.003327222222225;
    fix_list[1015].m_Longitude = 126.77567;

    TP080 = &fix_list[1016];
    fix_list[1016].m_Latitude = 37.52158333333333;
    fix_list[1016].m_Longitude = 126.53952777777778;

    TP120 = &fix_list[1017];
    fix_list[1017].m_Latitude = 37.40986111111111;
    fix_list[1017].m_Longitude = 126.2581388888889;

    TU521 = &fix_list[1018];
    fix_list[1018].m_Latitude = 36.7555;
    fix_list[1018].m_Longitude = 127.28863888888888;

    TU743 = &fix_list[1019];
    fix_list[1019].m_Latitude = 36.801472222222216;
    fix_list[1019].m_Longitude = 127.63469444444445;

    TU746 = &fix_list[1020];
    fix_list[1020].m_Latitude = 36.75561111111111;
    fix_list[1020].m_Longitude = 127.56044444444444;

    TU761 = &fix_list[1021];
    fix_list[1021].m_Latitude = 36.65694444444444;
    fix_list[1021].m_Longitude = 127.1413888888889;

    TU762 = &fix_list[1022];
    fix_list[1022].m_Latitude = 36.58941666666667;
    fix_list[1022].m_Longitude = 127.29266666666666;

    TU763 = &fix_list[1023];
    fix_list[1023].m_Latitude = 36.62002777777778;
    fix_list[1023].m_Longitude = 127.34180555555555;

    TU766 = &fix_list[1024];
    fix_list[1024].m_Latitude = 36.67858333333333;
    fix_list[1024].m_Longitude = 127.43608333333334;

    TURTU = &fix_list[1025];
    fix_list[1025].m_Latitude = 36.8575;
    fix_list[1025].m_Longitude = 127.7256388888889;

    TUTAE = &fix_list[1026];
    fix_list[1026].m_Latitude = 36.912324999999996;
    fix_list[1026].m_Longitude = 127.54148888888889;

    TUVRO = &fix_list[1027];
    fix_list[1027].m_Latitude = 35.126977777777775;
    fix_list[1027].m_Longitude = 128.19289194444445;

    TN311 = &fix_list[1028];
    fix_list[1028].m_Latitude = 35.839083333333335;
    fix_list[1028].m_Longitude = 128.4105;

    TN131 = &fix_list[1029];
    fix_list[1029].m_Latitude = 35.68058333333333;
    fix_list[1029].m_Longitude = 128.6820833333333;

    TN312 = &fix_list[1030];
    fix_list[1030].m_Latitude = 35.71413888888889;
    fix_list[1030].m_Longitude = 128.54630555555556;

    TN132 = &fix_list[1031];
    fix_list[1031].m_Latitude = 35.71216666666667;
    fix_list[1031].m_Longitude = 128.50205555555556;

    TN451 = &fix_list[1032];
    fix_list[1032].m_Latitude = 35.85308333333334;
    fix_list[1032].m_Longitude = 128.21513888888887;

    TN652 = &fix_list[1033];
    fix_list[1033].m_Latitude = 35.928666666666665;
    fix_list[1033].m_Longitude = 128.78250000000003;

    TN653 = &fix_list[1034];
    fix_list[1034].m_Latitude = 35.64336111111111;
    fix_list[1034].m_Longitude = 128.57572222222223;

    TN401 = &fix_list[1035];
    fix_list[1035].m_Latitude = 35.96725;
    fix_list[1035].m_Longitude = 128.35944444444445;

    TN403 = &fix_list[1036];
    fix_list[1036].m_Latitude = 35.97672222222222;
    fix_list[1036].m_Longitude = 128.508;

    TN603 = &fix_list[1037];
    fix_list[1037].m_Latitude = 35.85636111111111;
    fix_list[1037].m_Longitude = 128.72572222222223;

    TN633 = &fix_list[1038];
    fix_list[1038].m_Latitude = 35.65986111111111;
    fix_list[1038].m_Longitude = 128.6806388888889;

    UD050 = &fix_list[1039];
    fix_list[1039].m_Latitude = 37.500527777777776;
    fix_list[1039].m_Longitude = 126.86630555555556;

    TN503 = &fix_list[1040];
    fix_list[1040].m_Latitude = 35.977611111111116;
    fix_list[1040].m_Longitude = 128.50891666666666;

    UD060 = &fix_list[1041];
    fix_list[1041].m_Latitude = 37.37127777777778;
    fix_list[1041].m_Longitude = 126.91794444444444;

    TN601 = &fix_list[1042];
    fix_list[1042].m_Latitude = 35.85180555555556;
    fix_list[1042].m_Longitude = 128.97016666666667;

    TN602 = &fix_list[1043];
    fix_list[1043].m_Latitude = 35.79427777777778;
    fix_list[1043].m_Longitude = 128.83744444444446;

    TN701 = &fix_list[1044];
    fix_list[1044].m_Latitude = 35.795249999999996;
    fix_list[1044].m_Longitude = 128.83825000000002;

    TN702 = &fix_list[1045];
    fix_list[1045].m_Latitude = 35.85733333333334;
    fix_list[1045].m_Longitude = 128.72650000000002;

    UD080 = &fix_list[1046];
    fix_list[1046].m_Latitude = 37.23425;
    fix_list[1046].m_Longitude = 127.03572222222222;

    UD100 = &fix_list[1047];
    fix_list[1047].m_Latitude = 37.09066666666667;
    fix_list[1047].m_Longitude = 126.98069444444445;

    UPDET = &fix_list[1048];
    fix_list[1048].m_Latitude = 36.931;
    fix_list[1048].m_Longitude = 126.91980555555556;

    UGOVI = &fix_list[1049];
    fix_list[1049].m_Latitude = 37.68472222222222;
    fix_list[1049].m_Longitude = 129.8475;

    UG100 = &fix_list[1050];
    fix_list[1050].m_Latitude = 37.10669444444444;
    fix_list[1050].m_Longitude = 127.13719444444445;

    UG130 = &fix_list[1051];
    fix_list[1051].m_Latitude = 36.962694444444445;
    fix_list[1051].m_Longitude = 127.25033333333333;

    UKBAT = &fix_list[1052];
    fix_list[1052].m_Latitude = 35.938160555555555;
    fix_list[1052].m_Longitude = 128.94695305555555;

    ULSUK = &fix_list[1053];
    fix_list[1053].m_Latitude = 35.00666666666667;
    fix_list[1053].m_Longitude = 128.74055555555555;

    UMNAE = &fix_list[1054];
    fix_list[1054].m_Latitude = 36.94405555555555;
    fix_list[1054].m_Longitude = 129.39697222222222;

    UP050 = &fix_list[1055];
    fix_list[1055].m_Latitude = 37.39505555555556;
    fix_list[1055].m_Longitude = 126.9081388888889;

    UP059 = &fix_list[1056];
    fix_list[1056].m_Latitude = 37.412166666666664;
    fix_list[1056].m_Longitude = 126.59380555555555;

    UP060 = &fix_list[1057];
    fix_list[1057].m_Latitude = 37.358472222222225;
    fix_list[1057].m_Longitude = 126.76913888888889;

    UP100 = &fix_list[1058];
    fix_list[1058].m_Latitude = 37.41075;
    fix_list[1058].m_Longitude = 126.37327777777777;

    UPGOS = &fix_list[1059];
    fix_list[1059].m_Latitude = 33.95916666666667;
    fix_list[1059].m_Longitude = 127.33138888888888;

    UPLAP = &fix_list[1060];
    fix_list[1060].m_Latitude = 35.07217194444445;
    fix_list[1060].m_Longitude = 128.0502027777778;

    UPMAN = &fix_list[1061];
    fix_list[1061].m_Latitude = 36.15580555555555;
    fix_list[1061].m_Longitude = 126.55572222222222;

    UPREX = &fix_list[1062];
    fix_list[1062].m_Latitude = 35.135216944444444;
    fix_list[1062].m_Longitude = 128.18935277777777;

    UPROR = &fix_list[1063];
    fix_list[1063].m_Latitude = 37.54602777777777;
    fix_list[1063].m_Longitude = 126.3791111111111;

    UPSOM = &fix_list[1064];
    fix_list[1064].m_Latitude = 37.477444444444444;
    fix_list[1064].m_Longitude = 127.31786111111111;

    UPTAD = &fix_list[1065];
    fix_list[1065].m_Latitude = 37.455916944444446;
    fix_list[1065].m_Longitude = 127.18449972222223;

    UPTIL = &fix_list[1066];
    fix_list[1066].m_Latitude = 36.64991666666667;
    fix_list[1066].m_Longitude = 127.38994444444445;

    VASLI = &fix_list[1067];
    fix_list[1067].m_Latitude = 36.71246527777778;
    fix_list[1067].m_Longitude = 127.49944833333333;

    VASVA = &fix_list[1068];
    fix_list[1068].m_Latitude = 34.91652777777777;
    fix_list[1068].m_Longitude = 126.67966666666668;

    VATIS = &fix_list[1069];
    fix_list[1069].m_Latitude = 42.86193611111111;
    fix_list[1069].m_Longitude = 132.1475111111111;

    VELKI = &fix_list[1070];
    fix_list[1070].m_Latitude = 35.98902777777778;
    fix_list[1070].m_Longitude = 129.52497222222223;

    VEMUM = &fix_list[1071];
    fix_list[1071].m_Latitude = 37.539249999999996;
    fix_list[1071].m_Longitude = 127.33677777777777;

    VIPIR = &fix_list[1072];
    fix_list[1072].m_Latitude = 35.66499972222222;
    fix_list[1072].m_Longitude = 126.67247194444445;

    VISET = &fix_list[1073];
    fix_list[1073].m_Latitude = 35.987500000000004;
    fix_list[1073].m_Longitude = 129.3795;

    WAROB = &fix_list[1074];
    fix_list[1074].m_Latitude = 35.755833333333335;
    fix_list[1074].m_Longitude = 126.92875000000001;

    WASAN = &fix_list[1075];
    fix_list[1075].m_Latitude = 39.72833333333333;
    fix_list[1075].m_Longitude = 127.08388888888888;

    WAYBI = &fix_list[1076];
    fix_list[1076].m_Latitude = 35.10638888888889;
    fix_list[1076].m_Longitude = 128.84894444444444;

    WINTE = &fix_list[1077];
    fix_list[1077].m_Latitude = 35.11025;
    fix_list[1077].m_Longitude = 128.11397777777776;

    WONAP = &fix_list[1078];
    fix_list[1078].m_Latitude = 35.88308333333333;
    fix_list[1078].m_Longitude = 126.62097222222222;

    WONKO = &fix_list[1079];
    fix_list[1079].m_Latitude = 37.400555833333335;
    fix_list[1079].m_Longitude = 126.98555583333334;

    WWOLF = &fix_list[1080];
    fix_list[1080].m_Latitude = 35.94047222222222;
    fix_list[1080].m_Longitude = 126.91694444444445;

    WYZRD = &fix_list[1081];
    fix_list[1081].m_Latitude = 35.87947194444445;
    fix_list[1081].m_Longitude = 126.30602777777777;

    XEMIX = &fix_list[1082];
    fix_list[1082].m_Latitude = 34.9615;
    fix_list[1082].m_Longitude = 126.51494444444444;

    YAWAN = &fix_list[1083];
    fix_list[1083].m_Latitude = 35.87335361111111;
    fix_list[1083].m_Longitude = 128.3767836111111;

    YD020 = &fix_list[1084];
    fix_list[1084].m_Latitude = 37.50369444444444;
    fix_list[1084].m_Longitude = 126.36880555555555;

    YD040 = &fix_list[1085];
    fix_list[1085].m_Latitude = 37.50822222222222;
    fix_list[1085].m_Longitude = 126.18247222222223;

    YD070 = &fix_list[1086];
    fix_list[1086].m_Latitude = 37.408722222222224;
    fix_list[1086].m_Longitude = 126.13583333333334;

    YD100 = &fix_list[1087];
    fix_list[1087].m_Latitude = 37.32638888888889;
    fix_list[1087].m_Longitude = 126.2538888888889;

    YD130 = &fix_list[1088];
    fix_list[1088].m_Latitude = 37.19436111111111;
    fix_list[1088].m_Longitude = 126.44225;

    YD160 = &fix_list[1089];
    fix_list[1089].m_Latitude = 37.038777777777774;
    fix_list[1089].m_Longitude = 126.51616666666666;

    YD190 = &fix_list[1090];
    fix_list[1090].m_Latitude = 36.87730555555556;
    fix_list[1090].m_Longitude = 126.56944444444444;

    YEJEE = &fix_list[1091];
    fix_list[1091].m_Latitude = 36.69649999999999;
    fix_list[1091].m_Longitude = 127.46494444444444;

    YEOJU = &fix_list[1092];
    fix_list[1092].m_Latitude = 37.41289388888889;
    fix_list[1092].m_Longitude = 127.44718888888889;

    YEONA = &fix_list[1093];
    fix_list[1093].m_Latitude = 34.951055833333335;
    fix_list[1093].m_Longitude = 127.41447194444444;

    YG160 = &fix_list[1094];
    fix_list[1094].m_Latitude = 37.121805555555554;
    fix_list[1094].m_Longitude = 126.62913888888889;

    YK130 = &fix_list[1095];
    fix_list[1095].m_Latitude = 37.32461111111112;
    fix_list[1095].m_Longitude = 126.45863888888888;

    YK170 = &fix_list[1096];
    fix_list[1096].m_Latitude = 37.32172222222223;
    fix_list[1096].m_Longitude = 126.71077777777778;

    YK210 = &fix_list[1097];
    fix_list[1097].m_Latitude = 37.31813888888889;
    fix_list[1097].m_Longitude = 127.00872222222222;

    YOMJU = &fix_list[1098];
    fix_list[1098].m_Latitude = 40.01138888888889;
    fix_list[1098].m_Longitude = 124.77722222222222;

    YP080 = &fix_list[1099];
    fix_list[1099].m_Latitude = 37.40736111111111;
    fix_list[1099].m_Longitude = 125.99011111111112;

    YUMIN = &fix_list[1100];
    fix_list[1100].m_Latitude = 33.45713888888889;
    fix_list[1100].m_Longitude = 126.22097222222223;

    ZD080 = &fix_list[1101];
    fix_list[1101].m_Latitude = 37.2295;
    fix_list[1101].m_Longitude = 127.09530555555556;

    ZD100 = &fix_list[1102];
    fix_list[1102].m_Latitude = 37.14088888888889;
    fix_list[1102].m_Longitude = 127.19502777777778;

    ZD119 = &fix_list[1103];
    fix_list[1103].m_Latitude = 36.82508333333334;
    fix_list[1103].m_Longitude = 126.94466666666668;

    ZD120 = &fix_list[1104];
    fix_list[1104].m_Latitude = 37.037277777777774;
    fix_list[1104].m_Longitude = 127.19475;

    ZENZA = &fix_list[1105];
    fix_list[1105].m_Latitude = 36.78472222222222;
    fix_list[1105].m_Longitude = 127.60722222222222;

    ZG130 = &fix_list[1106];
    fix_list[1106].m_Latitude = 36.98386111111111;
    fix_list[1106].m_Longitude = 127.27488888888888;

    ZIKKO = &fix_list[1107];
    fix_list[1107].m_Latitude = 35.16336111111111;
    fix_list[1107].m_Longitude = 128.90216666666666;

    ZUDUX = &fix_list[1108];
    fix_list[1108].m_Latitude = 35.88352777777778;
    fix_list[1108].m_Longitude = 126.62072222222221;
}

