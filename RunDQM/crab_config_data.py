from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = 'Run_208352'
config.General.workArea = 'CRAB3_SingleMu-15Apr2014-AOD'

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'crab_DQM.py'
config.JobType.outputFiles = ['DQM_V0001_R000000001__7__0__0.root']

config.section_("Data")
config.Data.inputDataset = '/SingleMu/Run2012D-15Apr2014-v1/AOD'
config.Data.dbsUrl = 'global'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 20
config.Data.lumiMask = 'my_lumimask_file.txt'
#config.Data.runRange = '205834-205834'
config.Data.publication = False
config.Data.publishDbsUrl = 'phys03'
config.Data.publishDataName = 'Run2012D-15Apr2014-v1-AOD'

config.section_("Site")
config.Site.storageSite = 'T2_ES_IFCA' 
