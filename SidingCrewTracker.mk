##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=SidingCrewTracker
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/nlcor/Workspaces/Practice
ProjectPath            :=C:/Users/nlcor/Workspaces/Practice/SidingCrewTracker
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/SidingCrewTracker
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Neil
Date                   :=25/11/2023
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir
LinkerName             :=C:/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/Users/nlcor/Workspaces/Practice/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/mingw64/bin/windres.exe
LinkOptions            :=  -static
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/mingw64/bin/ar.exe -r
CXX      := C:/mingw64/bin/g++.exe
CC       := C:/mingw64/bin/gcc.exe
CXXFLAGS :=  -O0 -gdwarf-2 -std=c++17 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Jobs.cpp$(ObjectSuffix) $(IntermediateDirectory)/Crew.cpp$(ObjectSuffix) $(IntermediateDirectory)/Community.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/nlcor/Workspaces/Practice/SidingCrewTracker/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Jobs.cpp$(ObjectSuffix): Jobs.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/nlcor/Workspaces/Practice/SidingCrewTracker/Jobs.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Jobs.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Jobs.cpp$(PreprocessSuffix): Jobs.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Jobs.cpp$(PreprocessSuffix) Jobs.cpp

$(IntermediateDirectory)/Crew.cpp$(ObjectSuffix): Crew.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/nlcor/Workspaces/Practice/SidingCrewTracker/Crew.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Crew.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Crew.cpp$(PreprocessSuffix): Crew.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Crew.cpp$(PreprocessSuffix) Crew.cpp

$(IntermediateDirectory)/Community.cpp$(ObjectSuffix): Community.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/nlcor/Workspaces/Practice/SidingCrewTracker/Community.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Community.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Community.cpp$(PreprocessSuffix): Community.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Community.cpp$(PreprocessSuffix) Community.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


