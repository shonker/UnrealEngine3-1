class ParticleModuleSizeMultiplyLife extends ParticleModuleSizeBase
	native(Particle)
	editinlinenew
	collapsecategories
	hidecategories(Object);

var() editinlinenotify export noclear	distributionvector	LifeMultiplier;
var()									bool				MultiplyX;
var()									bool				MultiplyY;
var()									bool				MultiplyZ;

cpptext
{
	virtual void Spawn( FParticleEmitterInstance* Owner, INT Offset, FLOAT SpawnTime );
	virtual void Update( FParticleEmitterInstance* Owner, INT Offset, FLOAT DeltaTime );
}

defaultproperties
{
	bSpawnModule=true
	bUpdateModule=true

	MultiplyX=true
	MultiplyY=true
	MultiplyZ=true

	Begin Object Class=DistributionVectorConstant Name=DistributionLifeMultiplier
	End Object
	LifeMultiplier=DistributionLifeMultiplier
}