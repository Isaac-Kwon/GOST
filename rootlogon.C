{

   std::cout<<"==================="<<std::endl;
   std::cout<<"GOST ROOT"<<std::endl;

    TString DirName = TString(gSystem->GetWorkingDirectory());
    if( !(DirName.EndsWith("/build") || DirName.EndsWith("/build/")) ){
        DirName = DirName + TString("/build/");
    }

    if( !(DirName.EndsWith("/")) ){
        DirName = DirName + TString("/");
    }

   gInterpreter->AddIncludePath(TString::Format("%sinclude", DirName.Data()));
   Int_t Iinterpreter = gInterpreter->Load(TString::Format("%sGOST", DirName.Data()), true);

   std::cout<<"Include Path: " <<TString::Format("%sinclude", DirName.Data())<<std::endl;
   std::cout<<"Library Path: " <<TString::Format("%slibGOST", DirName.Data())<<std::endl;

   std::cout<<"GOST Library is loaded for TInterpreter."<<std::endl;
   std::cout<<"Please consider whether you are in same folder with libGOST file."<<std::endl;

   std::cout<<"==================="<<std::endl;

}
