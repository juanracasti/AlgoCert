void AlgoCert(TString dat_Run = "206390", TString ref_Run = "206940")
{

  TString fOutputDir = "Results/";
  char cmd[100];
  sprintf(cmd,"mkdir -p %s", fOutputDir.Data());
  system(cmd);

  TFile *fdat = TFile::Open("Samples/RecoMu_" + dat_Run + ".root");
  TFile *fref = TFile::Open("Samples/RecoMu_" + ref_Run + ".root");

  const int nRec = 3;

  enum {
    Glb,
    Tk,
    Sta
  };

  const TString sRec[nRec] = {
    "Global",
    "Tracker",
    "Standalone"
  };

  TH1F* hdat[nRec];
  TH1F* href[nRec];

  double D[nRec];
  double S[nRec];


  fdat->cd("DQMData/Run 1/Muons/Run summary/TightMuonRecoAnalyzer");
 
  hdat[Glb] = (TH1F*)gDirectory->Get("GlbMuon_Glb_chi2OverDf");
  hdat[Tk]  = (TH1F*)gDirectory->Get("GlbMuon_Tk_chi2OverDf");
  hdat[Sta] = (TH1F*)gDirectory->Get("GlbMuon_Sta_chi2OverDf"); 

  fref->cd("DQMData/Run 1/Muons/Run summary/TightMuonRecoAnalyzer");  

  href[Glb] = (TH1F*)gDirectory->Get("GlbMuon_Glb_chi2OverDf");
  href[Tk]  = (TH1F*)gDirectory->Get("GlbMuon_Tk_chi2OverDf");
  href[Sta] = (TH1F*)gDirectory->Get("GlbMuon_Sta_chi2OverDf");
  

  int nx1;
  int nx2;
  double xmin;
  double xmax;
  double sum1;
  double sum2;
  double s1;
  double s2;
  double psum1;
  double psum2;
  double d;
  double s;

  for (int iRec=0; iRec<nRec; iRec++)
    {

      nx1 = 0;
      nx2 = 0;
      xmin = 0;
      xmax = 0;
      sum1 = 0;
      sum2 = 0;

      nx1 = hdat[iRec]->GetXaxis()->GetNbins();
      nx2 = href[iRec]->GetXaxis()->GetNbins();

      xmin = hdat[iRec]->GetXaxis()->GetXmin();
      xmax = hdat[iRec]->GetXaxis()->GetXmax();
      
      if (nx1 != nx2) return -1;

      for (int bin=1;bin<=nx1;bin++)
	{
	  sum1 += hdat[iRec]->GetBinContent(bin);
	  sum2 += href[iRec]->GetBinContent(bin);
	}
      
      if (sum1 == 0 || sum2 == 0) return -1;
      
      s1 = 1/sum1;
      s2 = 1/sum2;
      psum1 = 0;
      psum2 = 0;
      d = 0;
      s = 0;

      for (int bin=1; bin<=nx1; bin++)
	{
	  psum1 += s1*hdat[iRec]->GetBinContent(bin);
	  psum2 += s2*href[iRec]->GetBinContent(bin);
	  d = TMath::Max(d,TMath::Abs(psum1-psum2));
	  s += TMath::Abs(psum1-psum2);
	}

      D[iRec] = d;
      S[iRec] = s;
    }

  // for (int i=0; i<nRec; i++)
  //   {
  //     printf("La maxima diferencia entre las distribuciones acumuladas del #chi^{2}/n.d.o.f. %s from Global es D = %.3f \n", sRec[i], D[i]);
  //     printf("La suma de la diferencia entre las distribuciones acumuladas del #chi^{2}/n.d.o.f. %s from Global es S = %.3f \n", sRec[i], S[i]);
  //   }

  printf("\n      Glb      Tk from Glb      Sta from Glb \n");
  printf("D    %.3f        %.3f             %.3f \n", D[0], D[1], D[2]);
  printf("S    %.3f        %.3f             %.3f \n", S[0], S[1], S[2]);

}
