
import FWCore.ParameterSet.Config as cms

process = cms.Process('DQM')

# import of standard configurations
process.load("DQMServices.Core.DQM_cfg")
process.load("DQMServices.Components.DQMEnvironment_cfi")

process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('DQMOffline.Configuration.DQMOffline_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

# Input source
process.source = cms.Source("PoolSource",
    secondaryFileNames = cms.untracked.vstring(),
    fileNames = cms.untracked.vstring()
)

process.options = cms.untracked.PSet()

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.19 $'),
    annotation = cms.untracked.string('test nevts:30'),
    name = cms.untracked.string('PyReleaseValidation')
)

process.DQM.collectorHost = ''
process.dqmSaver.convention = 'Offline' #Online
process.dqmSaver.saveByRun = 1 #0
process.dqmSaver.saveAtJobEnd = True
process.dqmSaver.forceRunNumber = cms.untracked.int32(000001)
process.dqmSaver.workflow = '/7/0/0'

# Additional output definition

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:com10', '')

# Path and EndPath definitions
process.dqmoffline_step = cms.Path(process.DQMOfflineMuon)
process.p = cms.EndPath(process.dqmSaver)
