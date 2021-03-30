#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//--
void petitNom(const string& className, string& varPetitNom)
{
 if (className.length()==0)
 {
  cerr << "petitNom: Nom de classe vide!"<< endl;
 }

 char   firstLetter = toupper(className.at(0));

 if (firstLetter=='A'||firstLetter=='E'||firstLetter=='I' ||
     firstLetter=='O'||firstLetter=='U'||firstLetter=='Y')   varPetitNom="an";
 else varPetitNom="a";

 varPetitNom += firstLetter;
}

//--
void transformeMajuscules(const string& src, string& dest)
{
 dest = src;
 for(size_t i=0; i<dest.length();i++)
 {
  char c = dest.at(i);
  dest.at(i)=toupper(c);
 }
}

//--
void saisieString(const string& mess, string& str)
{
 str="";

 while (str=="") { cout << mess;
                   cin  >> str;
 }
}

//--
void saisieSize_t(const string& mess, size_t &val)
{
 int ok = 0;
 
 while (ok!=1) {
                 string saisie;
                 unsigned int entier;
                 saisieString(mess,saisie);
                 ok = sscanf(saisie.c_str(),"%ud",&entier);
                 val = entier;
 }
}

//--
void usage(int argc,char **argv)
{
  (void)argc;
  cerr << endl;
  cerr << "Usage : " << argv[0] << "[-tn] ClassName" << endl;
  cerr << endl;
  cerr << "L'eventuelle option -t (classe template) est suivie d'un nombre n.";
  cerr << endl;
  cerr << "Ce nombre n correspond aux nombres de classes "
       << "parametrant ClassName.";
  cerr << endl;
  cerr << endl;
}

//--
int main(int argc, char **argv)
{
 if (argc==1 || argc > 3)
 { usage(argc,argv); return 1; } // Pas d'argument ou trop d'arguments !

 bool classTemplate = false;

 string allArgs="";
 for(int i=0;i<argc;i++)
 {
  allArgs += argv[i];
  if (i!=argc-1) allArgs += " ";
 }

 int nbTemplate, ok = sscanf(argv[1],"-t%d",&nbTemplate);
 if (ok == 1) {
                if (nbTemplate>0) classTemplate = true;

                for(int i=argc-1; i>1; i--) { argv[i-1] = argv[i]; }
                argv[argc-1]=NULL;
                argc--;
 }

 if (classTemplate) cout << endl << "Class Template"     << endl << endl;
 else               cout << endl << "Class non Template" << endl << endl;

 if (argc!=2) { usage(argc,argv); return 1; } // Deux classes ?

 string className;
 string CLASSNAME;
 string classNameT; // Comme classeName mais avec eventuellement du template
 string varName;
 string decName;
 string decName1;
 string decName2;
 string decNames12;

 size_t       nbBaseClasses;
 vector<string> baseClasses;

 string templateClassList="";
 string templateList="";

 if (classTemplate)
 {
  if (nbTemplate==1) {
    templateClassList="template <class T>";
    templateList="<T>"; 
  }
  else
  {
   templateClassList="template <";
   templateList="<";
   for(int i=1; i<=nbTemplate; i++)
   {
    ostringstream iToString;
    iToString << i;
    string s = "T";
    s = s + iToString.str();
    templateClassList+="class "+s;
    templateList+=s;
    if (i!=nbTemplate) { templateClassList+=", "; templateList+=","; }
   } 
   templateClassList+=">";
   templateList+=">";
  }
 }

 if (argc==1) saisieString("Nom de la classe ? ",className);
 else         className = argv[1];
 transformeMajuscules(className,CLASSNAME);
 petitNom(className,varName);

 classNameT =  className+templateList;
 decName    = "const "+classNameT+"& "+varName;
 decName1   =  decName+"1";
 decName2   =  decName+"2";
 decNames12 =  decName1+", "+decName2;
 
 saisieSize_t("Nombre de classes dont la classe "+className+" herite ? ",
              nbBaseClasses);

 for(size_t i=0; i<nbBaseClasses; i++)
 {
  string aBaseClasse;
  string ieme = " eme ";
  if (i==0) ieme = " ere ";

  ostringstream iPlus1ToString; iPlus1ToString << (i+1);

  saisieString("Nom de la " +
               iPlus1ToString.str() + ieme +
               "classe dont la classe " +
               className +
               " herite ? ",
               aBaseClasse);

  baseClasses.push_back(aBaseClasse);
 }

 // Ecriture du .h
 ///////////////////

 ofstream oh((className+".h").c_str());
 if (oh.fail()) { cerr << "Erreur ouverture fichier "
                       << className+".h" << endl;
                  return 1;
 }

 oh <<"                   // Fichier genere avec "<< allArgs << endl;

 oh << "#ifndef _"+CLASSNAME+"_H_" << endl;
 oh << "#define _"+CLASSNAME+"_H_" << endl;
 oh << endl;
 oh << "#include <iostream>" << endl;
 if (baseClasses.size()!=0) oh << endl;
 for(size_t i=0;i<baseClasses.size();i++)
 {
#if 1
  string newStr = baseClasses[i];
  size_t found = newStr.find_first_of("<");
  if (found != string::npos) newStr.resize(found);

  oh << "#include \""+newStr+".h\"" << endl;

#else

  oh << "#include \""+baseClasses[i]+".h\"" << endl;

#endif
 }
 oh << endl;
 oh << "using namespace std;" << endl;
 oh << endl;

/*
 // #define NEW_className(...) new className(__VA_ARGS__)

 oh << "#define NEW_"+className+"(...) new "+className+"(__VA_ARGS__)" << endl;
 oh << endl;
*/

 if (classTemplate)
 {
  oh                                                             << endl;
  oh << "//---- Pour les classes template avec fonctions amies"  << endl;
  oh                                                             << endl;
  oh << templateClassList << " " << "class " << className << ";" << endl;
  oh                                                             << endl;
  oh << templateClassList                                        << endl;
  oh << "ostream& operator<<(ostream& os, "+decName+");"         << endl;
  oh                                                             << endl;
  oh << templateClassList                                        << endl;
  oh << "bool operator==("+decName1+","                          << endl;
  oh << "                "+decName2+");"                         << endl;
  oh                                                             << endl;
  oh << templateClassList                                        << endl;
  oh << "bool operator!=("+decName1+","                          << endl;
  oh << "                "+decName2+");"                         << endl;
  oh                                                             << endl;
  oh << "//---------------------------------------------------"  << endl;
  oh                                                             << endl;
 }

 if (classTemplate) { oh << "//export"        << endl;
                      oh << templateClassList << endl;
 }
 oh << "class " << className;
 if (baseClasses.size()!=0) oh << " : ";
 for(size_t i=0;i<baseClasses.size();i++)
 {
  if (i!=0)
  {
   size_t nbBlancs = ("class "+className+" : ").length(); 
   for(size_t i=0;i<nbBlancs;i++) oh << ' ';
  }
  oh << "public "+baseClasses[i];
  if (i!=baseClasses.size()-1) oh << "," << endl;
 }

 oh << endl;
 oh << "{" << endl;
 if (classTemplate)
 {
  oh << "   friend ostream& operator<< <>(ostream& os, "+decName+");"<< endl;
 }
 else
 {
  oh << "   friend ostream& operator<<(ostream& os, "+decName+");"   << endl;
 }
 oh << endl;
 oh << " public :" << endl;
 oh << endl;
 oh << "   // Allocateurs/Desallocateurs" << endl;
 oh << endl;
 oh << "            "+className+"( /* ### */ );"                 << endl;
 oh << "            "+className+"("+decName+");"                 << endl;
 oh << "            "+classNameT+"& operator=("+decName+");"     << endl;
 oh << "   virtual ~"+className+"(void);"                        << endl;
 oh << endl;

 oh << "   // Comparaisons" << endl;
 oh << endl;
 if (classTemplate)
 {
  oh << "   friend  bool operator== <>("+decName1+","            << endl;
  oh << "                              "+decName2+");"           << endl;
  oh << "   friend  bool operator!= <>("+decName1+","            << endl;
  oh << "                              "+decName2+");"           << endl;
 }
 else
 {
  oh << "   friend  bool operator==("+decNames12+");"            << endl;
  oh << "   friend  bool operator!=("+decNames12+");"            << endl;
 }
 oh << endl;
 oh << "   // Inspecteurs/modificateurs" << endl;
 oh << endl;

 oh << " protected :" << endl;
 oh << endl;
 oh << "   // Methodes a appeler par une classe derivee" << endl;
 oh << endl;
 oh << "   // display: a appeler dans une classe derivee"
    << "      // display est une"                        << endl; 
 oh << "   virtual void display(ostream& os) const;"
    << "           // methode appelee"                   << endl;
 oh << "                                           "
    << "           // dans operator<<"                   << endl;
 oh << endl;
 oh << "   // isEqualTo: a appeler dans une classe derivee (dans operator==)";
 oh << endl;
 oh << "           bool isEqualTo("+decName+") const;"   << endl;

 oh << endl;
 oh << " protected :" << endl;
 oh << endl;
 oh << "             // ###" << endl;
 oh << endl;
 oh << " private :" << endl;
 oh << endl;
 oh << "             // ###" << endl;
 oh << endl;
 oh << " private :" << endl;
 oh << endl;
 oh << "   // Methodes privees d'allocation/desallocation" << endl;
 oh << endl;
 oh << "   void _copy("+decName+");" << endl;
 oh << "   void _destroy(void);"     << endl; 
 oh << "};" << endl;
 oh << endl;
 oh << "#endif // _"+CLASSNAME+"_H_" << endl;

 oh.close();

 // Ecriture du .cpp
 ///////////////////

 ofstream oc((className+".cpp").c_str());
 if (oc.fail()) { cerr << "Erreur ouverture fichier "
                       << className+".cpp" << endl;
                  return 1;
 }

 // L' include
 /////////////

 oc <<"                   // Fichier genere avec "<< allArgs << endl;

 oc << "#include \""+className+".h\"" << endl;
 oc << endl;

 // Le constructeur
 //////////////////
 oc << "//--" << endl;
 if (classTemplate) oc << templateClassList << endl;
 oc << classNameT+"::"+className+"( /* ### */ )";
 if (baseClasses.size()!=0) oc << " : ";
 for(size_t i=0;i<baseClasses.size();i++)
 {
  if (i!=0)
  {
   size_t nbBlancs = (className+"::"+className+
                      "( /* ### */ )"+" : ").length(); 
   for(size_t i=0;i<nbBlancs;i++) oc << ' ';
  }
  oc << baseClasses[i]+"( /* ### */ )";
  if (i!=baseClasses.size()-1) oc << "," << endl;
 }
 oc << endl;
 oc << "{" << endl;
 oc << "}" << endl;
 oc << endl;

 // Le constructeur par recopie
 //////////////////////////////

 oc << "//--" << endl;
 if (classTemplate) oc << templateClassList << endl;
 oc << classNameT << "::" << className << "("+decName+")";
 if (baseClasses.size()!=0) oc << " : ";
 for(size_t i=0;i<baseClasses.size();i++)
 {
  if (i!=0)
  {
   size_t nbBlancs = (className+"::"+className+"("+decName+")"+" : ").length(); 
   for(size_t i=0;i<nbBlancs;i++) oc << ' ';
  }
  oc << baseClasses[i] << "("+varName+")";
  if (i!=baseClasses.size()-1) oc << "," << endl;
 }
 oc << endl;
 oc << "{" << endl;
 oc << " _copy("+varName+");" << endl;
 oc << "}" << endl;
 oc << endl;

 // L'operator=
 //////////////

 oc << "//--" << endl;
 if (classTemplate) oc << templateClassList << endl;
 oc << classNameT << "& " << classNameT << "::operator=("+decName+")" << endl;
 oc << "{" << endl;
 oc << " if (this != &"+varName+")" << endl;
 oc << " {" << endl;
 for(size_t i=0;i<baseClasses.size();i++)
 {
 oc << "  "+baseClasses[i]+"::operator=("+varName+");" << endl;
 }
 oc << "  _destroy();" << endl;
 oc << "  _copy("+varName+");" << endl;
 oc << " }" << endl;
 oc << " return *this;" << endl;
 oc << "}" << endl;
 oc << endl;
 

 // Le destructeur
 //////////////////

 oc << "//--" << endl;
 if (classTemplate) oc << templateClassList << endl;
 oc << classNameT+"::~"+className+"(void)" << endl;
 oc << "{" << endl;
 oc << " _destroy();" << endl;
 oc << "}" << endl;
 oc << endl;

 // operator==
 /////////////

 oc << "//--" << endl;
 if (classTemplate) oc << templateClassList << endl;
 if (classTemplate)
 {
  oc << "bool operator==("+decName1+","                         << endl;
  oc << "                "+decName2+")"                         << endl;
 }
 else
 {
  oc << "bool operator==("+decNames12+")"                       <<endl;
 }
 oc << "{" << endl;
 oc << " return "+varName+"1.isEqualTo("+varName+"2);" << endl;
 oc << "}" << endl;
 oc << endl;

 // operator!=
 /////////////

 oc << "//--" << endl;
 if (classTemplate) oc << templateClassList << endl;
 if (classTemplate)
 {
  oc << "bool operator!=("+decName1+","                         << endl;
  oc << "                "+decName2+")"                         << endl;
 }
 else
 {
  oc << "bool operator!=("+decNames12+")" <<endl;
 }
 oc << "{" << endl;
 oc << " return !("+varName+"1=="+varName+"2);" << endl;
 oc << "}" << endl;
 oc << endl;

 // operator<<
 /////////////

 oc << "//--" << endl;
 if (classTemplate) oc << templateClassList << endl;
 oc << "ostream& operator<<(ostream& os, "+decName+")"<<endl;
 oc << "{" << endl;
 oc << " "+varName+".display(os);" << endl;
 oc << " return os;" << endl;
 oc << "}" << endl;
 oc << endl;

 // display
 ///////////

 oc << "//--" << endl;
 if (classTemplate) oc << templateClassList << endl;
 oc << "void "+classNameT+"::display(ostream& os) const" << endl;
 oc << "{" << endl;
 oc << " (void)os; // Pour eviter un warning si pas utilise" << endl << endl;
 for(size_t i=0;i<baseClasses.size();i++)
 {
 oc << " "+baseClasses[i]+"::display(os);" << endl;
 }
 if (baseClasses.size()!=0) oc << endl;
 oc << " // ### : Affichage des attributs de la classe " <<
                className << endl;
 oc << " // Exemple : os << _at;" << endl;
 oc << "}" << endl;
 oc << endl;

 // isEqualTo
 ////////////

 oc << "//--" << endl;
 if (classTemplate) oc << templateClassList << endl;
 oc << "bool "+classNameT+"::isEqualTo("+decName+") const"<<endl;
 oc << "{" << endl;
 oc << " (void)"+varName <<"; // Pour eviter un warning si pas utilise"
                         << endl
                         << endl;
 oc << " // ### : Test des attributs de la classe " <<
                className << endl;
 oc << " // Exemple : if (_at != "+varName+"._at) return false;" << endl;
 if (baseClasses.size()!=0) oc << endl;
 for(size_t i=0;i<baseClasses.size();i++)
 {
 oc << " if (!("<<baseClasses[i]+"::isEqualTo("+varName+"))) return false;"
    << endl;
 }
 oc << " return true;" << endl;
 oc << "}" << endl;
 oc << endl;

 // _copy
 /////////

 oc << "//--" << endl;
 if (classTemplate) oc << templateClassList << endl;
 oc << "void "+classNameT+"::_copy("+decName+")"<< endl;
 oc << "{" << endl;
 oc << " (void)" << varName <<"; // Pour eviter un warning si pas utilise"
                            << endl
                            << endl;
 oc << " // ### : Affectation des attributs de la classe "+className << endl;
 oc << " // Exemple : _at = "+varName+"._at;" << endl;
 oc << "}" << endl;
 oc << endl;

 // _destroy
 ////////////

 oc << "//--" << endl;
 if (classTemplate) oc << templateClassList << endl;
 oc << "void "+classNameT+"::_destroy(void)" << endl;
 oc << "{" << endl;
 oc << " // ### : Destruction des attributs de la classe "+className << endl;
 oc << " // Exemple : delete _at;" << endl;
 oc << "}" << endl;
 oc << endl;

 oc.close();

 return 0;
}
