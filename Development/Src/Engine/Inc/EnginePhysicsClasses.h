/*===========================================================================
    C++ class definitions exported from UnrealScript.
    This is automatically generated by the tools.
    DO NOT modify this manually! Edit the corresponding .uc files instead!
===========================================================================*/
#if SUPPORTS_PRAGMA_PACK
#pragma pack (push,4)
#endif


#ifndef NAMES_ONLY
#define AUTOGENERATE_NAME(name) extern FName ENGINE_##name;
#define AUTOGENERATE_FUNCTION(cls,idx,name)
#endif


#ifndef NAMES_ONLY


class AKAsset : public AActor
{
public:
    class USkeletalMeshComponent* SkeletalMeshComponent;
    BITFIELD bDamageAppliesImpulse:1 GCC_PACK(PROPERTY_ALIGNMENT);
    BITFIELD bWakeOnLevelStart:1;
    DECLARE_CLASS(AKAsset,AActor,0,Engine)
    NO_DEFAULT_CONSTRUCTOR(AKAsset)
};


class ASVehicle : public AVehicle
{
public:
    TArrayNoInit<class USVehicleWheel*> Wheels;
    BITFIELD bVehicleOnGround:1 GCC_PACK(PROPERTY_ALIGNMENT);
    DECLARE_CLASS(ASVehicle,AVehicle,0|CLASS_Config,Engine)
	// Actor interface.
	virtual void physRigidBody(FLOAT DeltaTime);
	virtual void TickSimulated( FLOAT DeltaSeconds );
	virtual void TickAuthoritative( FLOAT DeltaSeconds );
	virtual void setPhysics(BYTE NewPhysics, AActor *NewFloor, FVector NewFloorV);
	virtual void PostNetReceiveLocation();

#ifdef WITH_NOVODEX
	virtual void ModifyNxActorDesc(NxActorDesc& ActorDesc);
	virtual void PostInitRigidBody(NxActor* nActor);
#endif

	// SVehicle interface.

	/** 
	 *	This is called by ModifyNxActorDesc before it creates wheel capsule shapes and materials etc.
	 *	Allows subclasses to do last-minute paramter setting on the wheel. Don't create/destroy anything here though!
	 */
	virtual void PreInitVehicle() {}

	/**
	 *	SVehicle will update SlipVel and SlipAngle, then this allows a subclass to update the properties such as
	 *	Steer, DriveForce etc. Afterwards they will be applied to the vehicles physics.
	 */
	virtual void UpdateVehicle(FLOAT DeltaTime) {}
};


class ACar : public ASVehicle
{
public:
    FLOAT WheelSuspensionStiffness;
    FLOAT WheelSuspensionDamping;
    FLOAT WheelSuspensionBias;
    FInterpCurveFloat WheelLongFrictionFunc;
    FLOAT WheelLongFrictionScale;
    FLOAT WheelLatFrictionStatic;
    FLOAT WheelLatFrictionDynamic;
    FLOAT WheelRestitution;
    FLOAT WheelInertia;
    FLOAT WheelSuspensionMaxRenderTravel;
    FLOAT FTScale;
    FLOAT ChassisTorqueScale;
    FLOAT MinBrakeFriction;
    FInterpCurveFloat MaxSteerAngleCurve;
    FInterpCurveFloat TorqueCurve;
    FLOAT GearRatios[5];
    INT NumForwardGears;
    FLOAT TransRatio;
    FLOAT ChangeUpPoint;
    FLOAT ChangeDownPoint;
    FLOAT LSDFactor;
    FLOAT EngineBrakeFactor;
    FLOAT EngineBrakeRPMScale;
    FLOAT MaxBrakeTorque;
    FLOAT SteerSpeed;
    FLOAT StopThreshold;
    FLOAT EngineInertia;
    FLOAT IdleRPM;
    FLOAT OutputBrake;
    FLOAT OutputGas;
    INT Gear;
    FLOAT ForwardVel;
    BITFIELD bIsInverted:1 GCC_PACK(PROPERTY_ALIGNMENT);
    BITFIELD bIsDriving:1;
    INT NumPoweredWheels GCC_PACK(PROPERTY_ALIGNMENT);
    FLOAT TotalSpinVel;
    FLOAT EngineRPM;
    FLOAT CarMPH;
    FLOAT ActualSteering;
    FVector BaseOffset;
    FLOAT CamDist;
    DECLARE_CLASS(ACar,ASVehicle,0|CLASS_Config,Engine)
	// UObject interface
	virtual void PostEditChange(UProperty* PropertyThatChanged);

	// SVehicle interface.
	virtual void PreInitVehicle();
	virtual void UpdateVehicle(FLOAT DeltaTime);

	// SCar interface.
	void ProcessCarInput();
	void ChangeGear(UBOOL bReverse);
	void SyncWheelParams();
};


class ARB_ConstraintActor : public AActor
{
public:
    class AActor* ConstraintActor1;
    class AActor* ConstraintActor2;
    class URB_ConstraintSetup* ConstraintSetup;
    class URB_ConstraintInstance* ConstraintInstance;
    BITFIELD bDisableCollision:1 GCC_PACK(PROPERTY_ALIGNMENT);
    DECLARE_FUNCTION(execSetDisableCollision);
    DECLARE_CLASS(ARB_ConstraintActor,AActor,0,Engine)
	virtual void physRigidBody(FLOAT DeltaTime) {};
	virtual void PostEditMove();
	virtual void PostEditChange(UProperty* PropertyThatChanged);
	virtual void CheckForErrors(); // used for checking that this constraint is valid buring map build

	virtual void InitRBPhys();
	virtual void TermRBPhys();

	void SetDisableCollision(UBOOL NewDisableCollision);
};


class ARB_LineImpulseActor : public AActor
{
public:
    FLOAT ImpulseStrength;
    FLOAT ImpulseRange;
    BITFIELD bVelChange:1 GCC_PACK(PROPERTY_ALIGNMENT);
    BITFIELD bStopAtFirstHit:1;
    class UArrowComponent* Arrow GCC_PACK(PROPERTY_ALIGNMENT);
    DECLARE_FUNCTION(execFireLineImpulse);
    DECLARE_CLASS(ARB_LineImpulseActor,AActor,0,Engine)
	// UObject interface
	virtual void PostEditChange(UProperty* PropertyThatChanged);

	// ARB_LineImpulseActor interface
	void FireLineImpulse();
};


class ARB_Thruster : public AActor
{
public:
    BITFIELD bThrustEnabled:1 GCC_PACK(PROPERTY_ALIGNMENT);
    FLOAT ThrustStrength GCC_PACK(PROPERTY_ALIGNMENT);
    DECLARE_CLASS(ARB_Thruster,AActor,0,Engine)
	virtual UBOOL Tick( FLOAT DeltaSeconds, ELevelTick TickType );
};


class AKActor : public AStaticMeshActor
{
public:
    BITFIELD bDamageAppliesImpulse:1 GCC_PACK(PROPERTY_ALIGNMENT);
    BITFIELD bWakeOnLevelStart:1;
    FRigidBodyState RBState GCC_PACK(PROPERTY_ALIGNMENT);
    DECLARE_CLASS(AKActor,AStaticMeshActor,0,Engine)
	virtual void PreNetReceive();
	virtual void PostNetReceive();
};


class URB_ConstraintDrawComponent : public UPrimitiveComponent
{
public:
    class UMaterialInstance* LimitMaterial;
    DECLARE_CLASS(URB_ConstraintDrawComponent,UPrimitiveComponent,0,Engine)
	// Primitive Component interface
	virtual void Render(const FSceneContext& Context, struct FPrimitiveRenderInterface* PRI);
	virtual UBOOL Visible(FSceneView* View);
};


class URB_RadialImpulseComponent : public UPrimitiveComponent
{
public:
    BYTE ImpulseFalloff;
    FLOAT ImpulseStrength GCC_PACK(PROPERTY_ALIGNMENT);
    FLOAT ImpulseRadius;
    BITFIELD bVelChange:1 GCC_PACK(PROPERTY_ALIGNMENT);
    class UDrawSphereComponent* PreviewSphere GCC_PACK(PROPERTY_ALIGNMENT);
    DECLARE_FUNCTION(execFireImpulse);
    DECLARE_CLASS(URB_RadialImpulseComponent,UPrimitiveComponent,0,Engine)
	// UActorComponent interface
	virtual void Created();

	// RB_RadialImpulseComponent interface
	void FireImpulse();
};


class URB_Handle : public UActorComponent
{
public:
    class UPrimitiveComponent* GrabbedComponent;
    FName GrabbedBoneName;
    Fpointer HandleData;
    FVector GlobalHandlePos;
    FVector LocalHandlePos;
    FVector HandleAxis1;
    FVector HandleAxis2;
    FVector HandleAxis3;
    BITFIELD bRotationConstrained:1 GCC_PACK(PROPERTY_ALIGNMENT);
    FLOAT LinearDamping GCC_PACK(PROPERTY_ALIGNMENT);
    FLOAT LinearStiffness;
    FLOAT LinearMaxDistance;
    FLOAT AngularDamping;
    FLOAT AngularStiffness;
    DECLARE_FUNCTION(execSetOrientation);
    DECLARE_FUNCTION(execSetLocation);
    DECLARE_FUNCTION(execReleaseComponent);
    DECLARE_FUNCTION(execGrabComponent);
    DECLARE_CLASS(URB_Handle,UActorComponent,0,Engine)
	// UActorComponent interface
	virtual void Created();
	virtual void Destroyed();
	virtual void Tick(FLOAT DeltaTime);

	// URB_Handle interface
	void GrabComponent(UPrimitiveComponent* Component, FName InBoneName, const FVector& Location, UBOOL bConstrainRotation);
	void ReleaseComponent();

	void SetLocation(FVector NewLocation);
	void SetOrientation(FQuat NewOrientation);
};


class URB_Spring : public UActorComponent
{
public:
    class UPrimitiveComponent* Component1;
    FName BoneName1;
    class UPrimitiveComponent* Component2;
    FName BoneName2;
    Fpointer SpringData;
    FLOAT TimeSinceActivation;
    FLOAT MinBodyMass;
    FLOAT SpringSaturateDist;
    FLOAT SpringMaxForce;
    FLOAT MaxForceMassRatio;
    BITFIELD bEnableForceMassRatio:1 GCC_PACK(PROPERTY_ALIGNMENT);
    FInterpCurveFloat SpringMaxForceTimeScale GCC_PACK(PROPERTY_ALIGNMENT);
    FLOAT DampSaturateVel;
    FLOAT DampMaxForce;
    DECLARE_FUNCTION(execClear);
    DECLARE_FUNCTION(execSetComponents);
    DECLARE_CLASS(URB_Spring,UActorComponent,0,Engine)
	// ActorComponent interface

	virtual void Tick(FLOAT DeltaTime);

	// RB_Spring interface

	void SetComponents(UPrimitiveComponent* InComponent1, FName InBoneName1, FVector Position1, UPrimitiveComponent* InComponent2, FName InBoneName2, FVector Position2);
	void Clear();
};

enum EVehicleSteerType
{
    VST_Fixed               =0,
    VST_Steered             =1,
    VST_Inverted            =2,
    VST_MAX                 =3,
};

class USVehicleWheel : public UComponent
{
public:
    FLOAT Steer;
    FLOAT DriveForce;
    FLOAT ChassisTorque;
    BITFIELD bPoweredWheel:1 GCC_PACK(PROPERTY_ALIGNMENT);
    BITFIELD bWheelOnGround:1;
    BYTE SteerType GCC_PACK(PROPERTY_ALIGNMENT);
    BYTE BoneRollAxis;
    BYTE BoneSteerAxis;
    BYTE SupportBoneAxis;
    FName BoneName GCC_PACK(PROPERTY_ALIGNMENT);
    FVector BoneOffset;
    FLOAT WheelRadius;
    FLOAT SuspensionStiffness;
    FLOAT SuspensionDamping;
    FLOAT SuspensionBias;
    FLOAT LatFrictionStatic;
    FLOAT LatFrictionDynamic;
    FLOAT Restitution;
    FLOAT WheelInertia;
    FLOAT SuspensionMaxRenderTravel;
    FName SupportBoneName;
    FVector WheelPosition;
    FLOAT SupportPivotDistance;
    FLOAT TireLoad;
    FLOAT SpinVel;
    FLOAT SlipAngle;
    FLOAT SlipVel;
    FLOAT SuspensionPosition;
    FLOAT CurrentRotation;
    Fpointer RayShape;
    INT WheelMaterialIndex;
    DECLARE_CLASS(USVehicleWheel,UComponent,0,Engine)
    NO_DEFAULT_CONSTRUCTOR(USVehicleWheel)
};


class UPhysicalMaterial : public UObject
{
public:
    FLOAT Friction;
    FLOAT Restitution;
    FLOAT Density;
    FLOAT AngularDamping;
    FLOAT LinearDamping;
    FLOAT MagneticResponse;
    FLOAT WindResponse;
    INT MaterialIndex;
    DECLARE_CLASS(UPhysicalMaterial,UObject,0,Engine)
    NO_DEFAULT_CONSTRUCTOR(UPhysicalMaterial)
};


class URB_BodyInstance : public UObject
{
public:
    class AActor* Owner;
    INT BodyIndex;
    FVector Velocity;
    Fpointer BodyData;
    DECLARE_CLASS(URB_BodyInstance,UObject,0,Engine)
	void InitBody(class URB_BodySetup* setup, const FMatrix& transform, const FVector& Scale3D, UBOOL bFixed, UPrimitiveComponent* PrimComp);
	void TermBody();

	void SetFixed(UBOOL bNewFixed);

	FMatrix GetUnrealWorldTM();
	FVector GetUnrealWorldVelocity();

	void DrawCOMPosition( FPrimitiveRenderInterface* PRI, FLOAT COMRenderSize, const FColor& COMRenderColor );

#ifdef WITH_NOVODEX
	class NxActor* GetNxActor();
#endif
};


class URB_ConstraintInstance : public UObject
{
public:
    class AActor* Owner;
    Fpointer ConstraintData;
    DECLARE_CLASS(URB_ConstraintInstance,UObject,0,Engine)
	void InitConstraint(AActor* actor1, AActor* actor2, class URB_ConstraintSetup* setup, FLOAT Scale, AActor* inOwner);
	void TermConstraint();
};

struct FLinearDOFSetup
{
    BYTE bLimited;
    FLOAT LimitSize GCC_PACK(PROPERTY_ALIGNMENT);
};


class URB_ConstraintSetup : public UObject
{
public:
    FName JointName;
    FName ConstraintBone1;
    FName ConstraintBone2;
    FVector Pos1;
    FVector PriAxis1;
    FVector SecAxis1;
    FVector Pos2;
    FVector PriAxis2;
    FVector SecAxis2;
    FLinearDOFSetup LinearXSetup;
    FLinearDOFSetup LinearYSetup;
    FLinearDOFSetup LinearZSetup;
    FLOAT LinearStiffness;
    FLOAT LinearDamping;
    BITFIELD bLinearBreakable:1 GCC_PACK(PROPERTY_ALIGNMENT);
    BITFIELD bSwingLimited:1;
    BITFIELD bTwistLimited:1;
    BITFIELD bAngularBreakable:1;
    FLOAT LinearBreakThreshold GCC_PACK(PROPERTY_ALIGNMENT);
    FLOAT Swing1LimitAngle;
    FLOAT Swing2LimitAngle;
    FLOAT TwistLimitAngle;
    FLOAT AngularStiffness;
    FLOAT AngularDamping;
    FLOAT AngularBreakThreshold;
    DECLARE_CLASS(URB_ConstraintSetup,UObject,0,Engine)
	// UObject interface
	virtual void PostEditChange(UProperty* PropertyThatChanged);

	// Get/SetRefFrameMatrix only used in PhAT
	FMatrix GetRefFrameMatrix(INT BodyIndex);
	void SetRefFrameMatrix(INT BodyIndex, const FMatrix& RefFrame);

	void CopyConstraintGeometryFrom(class URB_ConstraintSetup* fromSetup);
	void CopyConstraintParamsFrom(class URB_ConstraintSetup* fromSetup);

	void DrawConstraint(struct FPrimitiveRenderInterface* PRI, 
		FLOAT Scale, UBOOL bDrawLimits, UBOOL bDrawSelected, UMaterialInstance* LimitMaterial,
		const FMatrix& Con1Frame, const FMatrix& Con2Frame);
};


class URB_BSJointSetup : public URB_ConstraintSetup
{
public:
    DECLARE_CLASS(URB_BSJointSetup,URB_ConstraintSetup,0,Engine)
    NO_DEFAULT_CONSTRUCTOR(URB_BSJointSetup)
};


class URB_HingeSetup : public URB_ConstraintSetup
{
public:
    DECLARE_CLASS(URB_HingeSetup,URB_ConstraintSetup,0,Engine)
    NO_DEFAULT_CONSTRUCTOR(URB_HingeSetup)
};


class URB_PrismaticSetup : public URB_ConstraintSetup
{
public:
    DECLARE_CLASS(URB_PrismaticSetup,URB_ConstraintSetup,0,Engine)
    NO_DEFAULT_CONSTRUCTOR(URB_PrismaticSetup)
};


class URB_SkelJointSetup : public URB_ConstraintSetup
{
public:
    DECLARE_CLASS(URB_SkelJointSetup,URB_ConstraintSetup,0,Engine)
    NO_DEFAULT_CONSTRUCTOR(URB_SkelJointSetup)
};

#endif

AUTOGENERATE_FUNCTION(ARB_ConstraintActor,-1,execSetDisableCollision);
AUTOGENERATE_FUNCTION(URB_Handle,-1,execSetOrientation);
AUTOGENERATE_FUNCTION(URB_Handle,-1,execSetLocation);
AUTOGENERATE_FUNCTION(URB_Handle,-1,execReleaseComponent);
AUTOGENERATE_FUNCTION(URB_Handle,-1,execGrabComponent);
AUTOGENERATE_FUNCTION(ARB_LineImpulseActor,-1,execFireLineImpulse);
AUTOGENERATE_FUNCTION(URB_RadialImpulseComponent,-1,execFireImpulse);
AUTOGENERATE_FUNCTION(URB_Spring,-1,execClear);
AUTOGENERATE_FUNCTION(URB_Spring,-1,execSetComponents);

#ifndef NAMES_ONLY
#undef AUTOGENERATE_NAME
#undef AUTOGENERATE_FUNCTION
#endif

#if SUPPORTS_PRAGMA_PACK
#pragma pack (pop)
#endif

