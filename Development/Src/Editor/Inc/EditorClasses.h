/*===========================================================================
    C++ class definitions exported from UnrealScript.
    This is automatically generated by the tools.
    DO NOT modify this manually! Edit the corresponding .uc files instead!
===========================================================================*/
#if SUPPORTS_PRAGMA_PACK
#pragma pack (push,4)
#endif


#ifndef NAMES_ONLY
#define AUTOGENERATE_NAME(name) extern FName EDITOR_##name;
#define AUTOGENERATE_FUNCTION(cls,idx,name)
#endif

AUTOGENERATE_NAME(Build)

#ifndef NAMES_ONLY


class AShape : public ABrush
{
public:
    DECLARE_CLASS(AShape,ABrush,0,Editor)
	virtual UBOOL IsAShape() {return true;}
	virtual void Spawned();
	virtual FColor GetWireColor();
};


struct BrushBuilder_eventBuild_Parms
{
    BITFIELD ReturnValue;
};
class UBrushBuilder : public UObject
{
public:
    FStringNoInit BitmapFilename;
    FStringNoInit ToolTip;
    TArrayNoInit<FVector> Vertices;
    TArrayNoInit<FBuilderPoly> Polys;
    FName Group;
    BITFIELD MergeCoplanars:1 GCC_PACK(PROPERTY_ALIGNMENT);
    DECLARE_FUNCTION(execPolyEnd);
    DECLARE_FUNCTION(execPolyi);
    DECLARE_FUNCTION(execPolyBegin);
    DECLARE_FUNCTION(execPoly4i);
    DECLARE_FUNCTION(execPoly3i);
    DECLARE_FUNCTION(execVertex3f);
    DECLARE_FUNCTION(execVertexv);
    DECLARE_FUNCTION(execBadParameters);
    DECLARE_FUNCTION(execGetPolyCount);
    DECLARE_FUNCTION(execGetVertex);
    DECLARE_FUNCTION(execGetVertexCount);
    DECLARE_FUNCTION(execEndBrush);
    DECLARE_FUNCTION(execBeginBrush);
    BITFIELD eventBuild()
    {
        BrushBuilder_eventBuild_Parms Parms;
        Parms.ReturnValue=0;
        ProcessEvent(FindFunctionChecked(EDITOR_Build),&Parms);
        return Parms.ReturnValue;
    }
    DECLARE_CLASS(UBrushBuilder,UObject,0,Editor)
    #include "UBrushBuilder.h"
};


class UGeomModifier : public UObject
{
public:
    FStringNoInit Description;
    BITFIELD bPushButton:1 GCC_PACK(PROPERTY_ALIGNMENT);
    BITFIELD bInitialized:1;
    DECLARE_CLASS(UGeomModifier,UObject,0,Editor)
	FString GetModifierDescription() { return Description; }
	
	virtual UBOOL InputDelta(struct FEditorLevelViewportClient* InViewportClient,FChildViewport* InViewport,FVector& InDrag,FRotator& InRot,FVector& InScale);
	
	/**
	 * Displays an error message for a modifier.
	 */
	void GeomError( FString InMsg );
	
	/**
	 * Applies any values the user may have entered into this modifiers
	 * "Keyboard" section of variables in the property window.
	 */
	 
	virtual UBOOL Supports( int InSelType ) { return 1; }
	
	/**
	 * Starts and ends the modification of geometry data.
	 */
	 
	virtual UBOOL StartModify();
	virtual UBOOL EndModify();
	
	/**
	 * Gives the individual modifiers a chance to do something the first time they are activated.
	 */
	virtual void Initialize() {}
	
	/**
	 * Determines if this modifier supports a specific selection mode.
	 *
	 * @param	InSelType	The selection type being checked
	 */
	 
	virtual void Apply() {}

	/**
	 * Handles the starting/stopping of transactions against the selected ABrushes
	 */

	void StartTrans();
	void EndTrans();
};


class UGeomModifier_Edit : public UGeomModifier
{
public:
    DECLARE_CLASS(UGeomModifier_Edit,UGeomModifier,0,Editor)
	virtual UBOOL InputDelta(struct FEditorLevelViewportClient* InViewportClient,FChildViewport* InViewport,FVector& InDrag,FRotator& InRot,FVector& InScale);
	
};


class UGeomModifier_Create : public UGeomModifier_Edit
{
public:
    DECLARE_CLASS(UGeomModifier_Create,UGeomModifier_Edit,0,Editor)
	virtual UBOOL Supports( int InSelType );
	virtual void Apply();
};


class UGeomModifier_Delete : public UGeomModifier_Edit
{
public:
    DECLARE_CLASS(UGeomModifier_Delete,UGeomModifier_Edit,0,Editor)
	virtual UBOOL Supports( int InSelType );
	virtual void Apply();
};


class UGeomModifier_Extrude : public UGeomModifier_Edit
{
public:
    INT Length;
    INT Segments;
    DECLARE_CLASS(UGeomModifier_Extrude,UGeomModifier_Edit,0,Editor)
	virtual UBOOL Supports( int InSelType );
	virtual void Apply();
	virtual void Initialize();
	
	void Apply( int InLength, int InSegments );
};


class UGeomModifier_Flip : public UGeomModifier_Edit
{
public:
    DECLARE_CLASS(UGeomModifier_Flip,UGeomModifier_Edit,0,Editor)
	virtual UBOOL Supports( int InSelType );
	virtual void Apply();
};


class UGeomModifier_Lathe : public UGeomModifier_Edit
{
public:
    INT TotalSegments;
    INT Segments;
    BYTE Axis;
    DECLARE_CLASS(UGeomModifier_Lathe,UGeomModifier_Edit,0,Editor)
	virtual UBOOL Supports( int InSelType );
	virtual void Apply();
	virtual void Initialize();
	
	void Apply( int InTotalSegments, int InSegments, EAxis InAxis );
};


class UGeomModifier_Split : public UGeomModifier_Edit
{
public:
    DECLARE_CLASS(UGeomModifier_Split,UGeomModifier_Edit,0,Editor)
	virtual UBOOL Supports( int InSelType );
	virtual void Apply();
};


class UGeomModifier_Triangulate : public UGeomModifier_Edit
{
public:
    DECLARE_CLASS(UGeomModifier_Triangulate,UGeomModifier_Edit,0,Editor)
	virtual UBOOL Supports( int InSelType );
	virtual void Apply();
};


class UGeomModifier_Turn : public UGeomModifier_Edit
{
public:
    DECLARE_CLASS(UGeomModifier_Turn,UGeomModifier_Edit,0,Editor)
	virtual UBOOL Supports( int InSelType );
	virtual void Apply();
};


class UGeomModifier_Weld : public UGeomModifier_Edit
{
public:
    DECLARE_CLASS(UGeomModifier_Weld,UGeomModifier_Edit,0,Editor)
	virtual UBOOL Supports( int InSelType );
	virtual void Apply();
};


class UEditorViewportInput : public UInput
{
public:
    class UEditorEngine* Editor;
    DECLARE_CLASS(UEditorViewportInput,UInput,0|CLASS_Transient|CLASS_Config,Editor)
	virtual UBOOL Exec(const TCHAR* Cmd,FOutputDevice& Ar);
};

#endif

AUTOGENERATE_FUNCTION(UBrushBuilder,-1,execPolyEnd);
AUTOGENERATE_FUNCTION(UBrushBuilder,-1,execPolyi);
AUTOGENERATE_FUNCTION(UBrushBuilder,-1,execPolyBegin);
AUTOGENERATE_FUNCTION(UBrushBuilder,-1,execPoly4i);
AUTOGENERATE_FUNCTION(UBrushBuilder,-1,execPoly3i);
AUTOGENERATE_FUNCTION(UBrushBuilder,-1,execVertex3f);
AUTOGENERATE_FUNCTION(UBrushBuilder,-1,execVertexv);
AUTOGENERATE_FUNCTION(UBrushBuilder,-1,execBadParameters);
AUTOGENERATE_FUNCTION(UBrushBuilder,-1,execGetPolyCount);
AUTOGENERATE_FUNCTION(UBrushBuilder,-1,execGetVertex);
AUTOGENERATE_FUNCTION(UBrushBuilder,-1,execGetVertexCount);
AUTOGENERATE_FUNCTION(UBrushBuilder,-1,execEndBrush);
AUTOGENERATE_FUNCTION(UBrushBuilder,-1,execBeginBrush);

#ifndef NAMES_ONLY
#undef AUTOGENERATE_NAME
#undef AUTOGENERATE_FUNCTION
#endif

#if SUPPORTS_PRAGMA_PACK
#pragma pack (pop)
#endif

#ifdef STATIC_LINKING_MOJO
#ifndef EDITOR_NATIVE_DEFS
#define EDITOR_NATIVE_DEFS

DECLARE_NATIVE_TYPE(Editor,UBrushBuilder);
DECLARE_NATIVE_TYPE(Editor,UEditorViewportInput);
DECLARE_NATIVE_TYPE(Editor,UGeomModifier);
DECLARE_NATIVE_TYPE(Editor,UGeomModifier_Create);
DECLARE_NATIVE_TYPE(Editor,UGeomModifier_Delete);
DECLARE_NATIVE_TYPE(Editor,UGeomModifier_Edit);
DECLARE_NATIVE_TYPE(Editor,UGeomModifier_Extrude);
DECLARE_NATIVE_TYPE(Editor,UGeomModifier_Flip);
DECLARE_NATIVE_TYPE(Editor,UGeomModifier_Lathe);
DECLARE_NATIVE_TYPE(Editor,UGeomModifier_Split);
DECLARE_NATIVE_TYPE(Editor,UGeomModifier_Triangulate);
DECLARE_NATIVE_TYPE(Editor,UGeomModifier_Turn);
DECLARE_NATIVE_TYPE(Editor,UGeomModifier_Weld);
DECLARE_NATIVE_TYPE(Editor,AShape);

#define AUTO_INITIALIZE_REGISTRANTS_EDITOR \
	UAnalyzeBuildCommandlet::StaticClass(); \
	UAnalyzeScriptCommandlet::StaticClass(); \
	UAnimSetFactoryNew::StaticClass(); \
	UAnimTreeFactoryNew::StaticClass(); \
	UBatchExportCommandlet::StaticClass(); \
	UBrushBuilder::StaticClass(); \
	GNativeLookupFuncs[Lookup++] = &FindEditorUBrushBuilderNative; \
	UCheckUnicodeCommandlet::StaticClass(); \
	UClassExporterUC::StaticClass(); \
	UClassFactoryNew::StaticClass(); \
	UClassFactoryUC::StaticClass(); \
	UComponentExporterT3D::StaticClass(); \
	UConformCommandlet::StaticClass(); \
	UConvertTextures::StaticClass(); \
	UCookPackagesXenon::StaticClass(); \
	UCreateStreamingLevel::StaticClass(); \
	UCutdownPackages::StaticClass(); \
	UEditorComponent::StaticClass(); \
	UEditorEngine::StaticClass(); \
	UEditorPlayer::StaticClass(); \
	UEditorViewportInput::StaticClass(); \
	UEdModeComponent::StaticClass(); \
	UFontFactory::StaticClass(); \
	UGeomModifier::StaticClass(); \
	UGeomModifier_Create::StaticClass(); \
	UGeomModifier_Delete::StaticClass(); \
	UGeomModifier_Edit::StaticClass(); \
	UGeomModifier_Extrude::StaticClass(); \
	UGeomModifier_Flip::StaticClass(); \
	UGeomModifier_Lathe::StaticClass(); \
	UGeomModifier_Split::StaticClass(); \
	UGeomModifier_Triangulate::StaticClass(); \
	UGeomModifier_Turn::StaticClass(); \
	UGeomModifier_Weld::StaticClass(); \
	ULevelExporterOBJ::StaticClass(); \
	ULevelExporterSTL::StaticClass(); \
	ULevelExporterT3D::StaticClass(); \
	ULevelFactory::StaticClass(); \
	ULevelFactoryNew::StaticClass(); \
	UListExports::StaticClass(); \
	ULoadPackage::StaticClass(); \
	UMakeCommandlet::StaticClass(); \
	UMaterialFactoryNew::StaticClass(); \
	UMaterialInstanceConstantFactoryNew::StaticClass(); \
	UModelExporterT3D::StaticClass(); \
	UModelFactory::StaticClass(); \
	UObjectExporterT3D::StaticClass(); \
	UPackageFlagCommandlet::StaticClass(); \
	UParticleSystemFactoryNew::StaticClass(); \
	UPolysExporterT3D::StaticClass(); \
	UPolysFactory::StaticClass(); \
	UPrefab::StaticClass(); \
	UPrefabExporterT3D::StaticClass(); \
	UPrefabFactory::StaticClass(); \
	URebuildCommandlet::StaticClass(); \
	UReimportTextures::StaticClass(); \
	UResavePackages::StaticClass(); \
	USequenceExporterT3D::StaticClass(); \
	USequenceFactory::StaticClass(); \
	AShape::StaticClass(); \
	USkeletalMeshFactory::StaticClass(); \
	USoundCueFactoryNew::StaticClass(); \
	USoundExporterWAV::StaticClass(); \
	USoundFactory::StaticClass(); \
	USphericalHarmonicMapFactorySHM::StaticClass(); \
	UStaticMeshExporterT3D::StaticClass(); \
	UStaticMeshFactory::StaticClass(); \
	UStripSourceCommandlet::StaticClass(); \
	UTerrainLayerSetupFactoryNew::StaticClass(); \
	UTerrainMaterialFactoryNew::StaticClass(); \
	UTextBufferExporterTXT::StaticClass(); \
	UTextureCubeFactoryNew::StaticClass(); \
	UTextureExporterBMP::StaticClass(); \
	UTextureExporterPCX::StaticClass(); \
	UTextureExporterTGA::StaticClass(); \
	UTextureFactory::StaticClass(); \
	UTextureMovieFactory::StaticClass(); \
	UTransactor::StaticClass(); \
	UTransBuffer::StaticClass(); \
	UTrueTypeFontFactory::StaticClass(); \
	UVolumeTextureFactory::StaticClass(); \

#endif // EDITOR_NATIVE_DEFS

#ifdef NATIVES_ONLY
NATIVE_INFO(UBrushBuilder) GEditorUBrushBuilderNatives[] = 
{ 
	MAP_NATIVE(UBrushBuilder,execPolyEnd)
	MAP_NATIVE(UBrushBuilder,execPolyi)
	MAP_NATIVE(UBrushBuilder,execPolyBegin)
	MAP_NATIVE(UBrushBuilder,execPoly4i)
	MAP_NATIVE(UBrushBuilder,execPoly3i)
	MAP_NATIVE(UBrushBuilder,execVertex3f)
	MAP_NATIVE(UBrushBuilder,execVertexv)
	MAP_NATIVE(UBrushBuilder,execBadParameters)
	MAP_NATIVE(UBrushBuilder,execGetPolyCount)
	MAP_NATIVE(UBrushBuilder,execGetVertex)
	MAP_NATIVE(UBrushBuilder,execGetVertexCount)
	MAP_NATIVE(UBrushBuilder,execEndBrush)
	MAP_NATIVE(UBrushBuilder,execBeginBrush)
	{NULL,NULL}
};
IMPLEMENT_NATIVE_HANDLER(Editor,UBrushBuilder);

#endif // NATIVES_ONLY
#endif // STATIC_LINKING_MOJO

#ifdef VERIFY_CLASS_SIZES
VERIFY_CLASS_SIZE_NODIE(UAnalyzeBuildCommandlet)
VERIFY_CLASS_SIZE_NODIE(UAnalyzeScriptCommandlet)
VERIFY_CLASS_SIZE_NODIE(UAnimSetFactoryNew)
VERIFY_CLASS_SIZE_NODIE(UAnimTreeFactoryNew)
VERIFY_CLASS_SIZE_NODIE(UBatchExportCommandlet)
VERIFY_CLASS_SIZE_NODIE(UBrushBuilder)
VERIFY_CLASS_SIZE_NODIE(UCheckUnicodeCommandlet)
VERIFY_CLASS_SIZE_NODIE(UClassExporterUC)
VERIFY_CLASS_SIZE_NODIE(UClassFactoryNew)
VERIFY_CLASS_SIZE_NODIE(UClassFactoryUC)
VERIFY_CLASS_SIZE_NODIE(UComponentExporterT3D)
VERIFY_CLASS_SIZE_NODIE(UConformCommandlet)
VERIFY_CLASS_SIZE_NODIE(UConvertTextures)
VERIFY_CLASS_SIZE_NODIE(UCookPackagesXenon)
VERIFY_CLASS_SIZE_NODIE(UCreateStreamingLevel)
VERIFY_CLASS_SIZE_NODIE(UCutdownPackages)
VERIFY_CLASS_SIZE_NODIE(UEditorComponent)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,Level)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,PlayLevel)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,TempModel)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,Trans)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,Results)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,ActorProperties)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,LevelProperties)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,UseDest)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,AutosaveCounter)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,Bad)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,Bkgnd)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,BkgndHi)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,BadHighlight)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,MaterialArrow)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,MaterialBackdrop)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,TexPropCube)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,TexPropSphere)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,TexPropPlane)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,TexPropCylinder)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,AutoSaveIndex)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,AutoSaveCount)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,TerrainEditBrush)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,ClickFlags)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,MovementSpeed)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,ParentContext)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,ClickLocation)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,ClickPlane)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,MouseMovement)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,ViewportClients)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,Tools)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,BrowseClass)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,FOVAngle)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,AutosaveTimeMinutes)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,AutoSaveDir)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,GameCommandLine)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,EditPackages)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,EditPackagesInPath)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,EditPackagesOutPath)
VERIFY_CLASS_OFFSET_NODIE(U,EditorEngine,ActorFactories)
VERIFY_CLASS_SIZE_NODIE(UEditorEngine)
VERIFY_CLASS_SIZE_NODIE(UEditorPlayer)
VERIFY_CLASS_SIZE_NODIE(UEditorViewportInput)
VERIFY_CLASS_SIZE_NODIE(UEdModeComponent)
VERIFY_CLASS_SIZE_NODIE(UFontFactory)
VERIFY_CLASS_SIZE_NODIE(UGeomModifier)
VERIFY_CLASS_SIZE_NODIE(UGeomModifier_Create)
VERIFY_CLASS_SIZE_NODIE(UGeomModifier_Delete)
VERIFY_CLASS_SIZE_NODIE(UGeomModifier_Edit)
VERIFY_CLASS_SIZE_NODIE(UGeomModifier_Extrude)
VERIFY_CLASS_SIZE_NODIE(UGeomModifier_Flip)
VERIFY_CLASS_SIZE_NODIE(UGeomModifier_Lathe)
VERIFY_CLASS_SIZE_NODIE(UGeomModifier_Split)
VERIFY_CLASS_SIZE_NODIE(UGeomModifier_Triangulate)
VERIFY_CLASS_SIZE_NODIE(UGeomModifier_Turn)
VERIFY_CLASS_SIZE_NODIE(UGeomModifier_Weld)
VERIFY_CLASS_SIZE_NODIE(ULevelExporterOBJ)
VERIFY_CLASS_SIZE_NODIE(ULevelExporterSTL)
VERIFY_CLASS_SIZE_NODIE(ULevelExporterT3D)
VERIFY_CLASS_SIZE_NODIE(ULevelFactory)
VERIFY_CLASS_SIZE_NODIE(ULevelFactoryNew)
VERIFY_CLASS_SIZE_NODIE(UListExports)
VERIFY_CLASS_SIZE_NODIE(ULoadPackage)
VERIFY_CLASS_SIZE_NODIE(UMakeCommandlet)
VERIFY_CLASS_SIZE_NODIE(UMaterialFactoryNew)
VERIFY_CLASS_SIZE_NODIE(UMaterialInstanceConstantFactoryNew)
VERIFY_CLASS_SIZE_NODIE(UModelExporterT3D)
VERIFY_CLASS_SIZE_NODIE(UModelFactory)
VERIFY_CLASS_SIZE_NODIE(UObjectExporterT3D)
VERIFY_CLASS_SIZE_NODIE(UPackageFlagCommandlet)
VERIFY_CLASS_SIZE_NODIE(UParticleSystemFactoryNew)
VERIFY_CLASS_SIZE_NODIE(UPolysExporterT3D)
VERIFY_CLASS_SIZE_NODIE(UPolysFactory)
VERIFY_CLASS_SIZE_NODIE(UPrefab)
VERIFY_CLASS_SIZE_NODIE(UPrefabExporterT3D)
VERIFY_CLASS_SIZE_NODIE(UPrefabFactory)
VERIFY_CLASS_SIZE_NODIE(URebuildCommandlet)
VERIFY_CLASS_SIZE_NODIE(UReimportTextures)
VERIFY_CLASS_SIZE_NODIE(UResavePackages)
VERIFY_CLASS_SIZE_NODIE(USequenceExporterT3D)
VERIFY_CLASS_SIZE_NODIE(USequenceFactory)
VERIFY_CLASS_SIZE_NODIE(AShape)
VERIFY_CLASS_SIZE_NODIE(USkeletalMeshFactory)
VERIFY_CLASS_SIZE_NODIE(USoundCueFactoryNew)
VERIFY_CLASS_SIZE_NODIE(USoundExporterWAV)
VERIFY_CLASS_SIZE_NODIE(USoundFactory)
VERIFY_CLASS_SIZE_NODIE(USphericalHarmonicMapFactorySHM)
VERIFY_CLASS_SIZE_NODIE(UStaticMeshExporterT3D)
VERIFY_CLASS_SIZE_NODIE(UStaticMeshFactory)
VERIFY_CLASS_SIZE_NODIE(UStripSourceCommandlet)
VERIFY_CLASS_SIZE_NODIE(UTerrainLayerSetupFactoryNew)
VERIFY_CLASS_SIZE_NODIE(UTerrainMaterialFactoryNew)
VERIFY_CLASS_SIZE_NODIE(UTextBufferExporterTXT)
VERIFY_CLASS_SIZE_NODIE(UTextureCubeFactoryNew)
VERIFY_CLASS_SIZE_NODIE(UTextureExporterBMP)
VERIFY_CLASS_SIZE_NODIE(UTextureExporterPCX)
VERIFY_CLASS_SIZE_NODIE(UTextureExporterTGA)
VERIFY_CLASS_SIZE_NODIE(UTextureFactory)
VERIFY_CLASS_SIZE_NODIE(UTextureMovieFactory)
VERIFY_CLASS_SIZE_NODIE(UTransactor)
VERIFY_CLASS_SIZE_NODIE(UTransBuffer)
VERIFY_CLASS_SIZE_NODIE(UTrueTypeFontFactory)
VERIFY_CLASS_SIZE_NODIE(UVolumeTextureFactory)
#endif // VERIFY_CLASS_SIZES
