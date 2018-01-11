#! /usr/bin/env python
import os

if __name__ == "__main__":
    from optparse import OptionParser
    parser = OptionParser(usage="%prog [options] filelist.txt")
    parser.add_option("-c","--create", dest="create",  action="store_true", default=False, help="do not submit jobs, only show the submission command")
    (options, args) = parser.parse_args()
    if len(args) < 1: raise RuntimeError, 'Expecting at least the filelist as argument'

# CUSTOMIZE THE RUN RANGES HERE
ranges = {
#    278167:278175,
#    283863:284035,
#    283171:283835,
#    282408:283067,
#    281616:282092,
#    293765:293910
#    298809:298809
#    299481:299481
#    300157:300157
#    300574:300576
#    301141:301165
#    301472:301480
#     302026:302044 # fill 6147
#    302634:302635 # fill 6191
#    304209:304292 # fills 6263_6266
#     303838:303838 # fill 6241   
#    304797:304797
#    304740:304740
#    305832:305842
#    305814:305814
#    306121:306126
    306896:307082
    }

pwd = os.getcwd()

for start,stop in ranges.iteritems():
    comm = 'bsub -q cmscaf1nd -J '+str(start)+'_'+str(stop)+' -o psana_runs_'+str(start)+'_'+str(stop)+'.log '+pwd+'/submitPulseShapeAnalysisOneRange.sh '+str(start)+' '+str(stop)+' '+args[0]
    if options.create: print comm
    else: os.system(comm)

print 'DONE.'

