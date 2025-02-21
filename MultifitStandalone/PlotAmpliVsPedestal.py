#! /usr/bin/env python
import ROOT
import root_numpy as rtnp

if __name__ == "__main__":

    ROOT.gStyle.SetOptStat(0)
    tf = ROOT.TFile.Open("data/reco_signal_50GeV_eta_0.0_pu_40_shiftped.root")
    tree = tf.Get("amplitudes")
    hsteps = tf.Get("hsteps")

    steps = rtnp.hist2array(hsteps)
    print steps

    gr = ROOT.TGraphErrors(len(steps))
    gr.SetTitle("")
    for i,s in enumerate(steps):
        hist = ROOT.TH1D("hist","",1000,0.95,1.05)
        tree.Draw("amplitude[{i}]/amplitudeTruth>>hist".format(i=i))
        bias = hist.GetMean()
        err = hist.GetMeanError()
        print "pedshift = {dp} => bias = {bias}".format(dp=s,bias=bias)

        gr.SetPoint(i,s,bias)
        gr.SetPointError(i,0,err)


    lat = ROOT.TLatex()
    lat.SetNDC(); lat.SetTextFont(42)
    
    canv = ROOT.TCanvas("canv","",1200,1200)
    canv.SetGridx()
    canv.SetGridy()
    canv.SetLeftMargin(0.17)
    canv.SetRightMargin(0.1)
    canv.SetBottomMargin(0.15)
    gr.SetMarkerStyle(ROOT.kFullCircle)
    gr.SetMarkerSize(1.5)
    gr.Draw("ACPE")
    xax = gr.GetXaxis(); yax = gr.GetYaxis()
    xax.SetRangeUser(-1.0,1.0)
    yax.SetRangeUser(0.994,1.006)
    yax.SetDecimals()
    xax.SetTitleOffset(1.1); xax.SetTitleSize(0.05)
    yax.SetTitleOffset(1.5); yax.SetTitleSize(0.05)
    xax.SetTitle('#Delta P (ADC counts)')
    yax.SetTitle('A/A_{true}')

    lat.DrawLatex(0.19, 0.92, '#bf{CMS}')
    lat.DrawLatex(0.73, 0.92, '(13 TeV)')
    canv.SaveAs("bias_vs_dped.pdf")
    
