

#include "IndieProject.h"
#include "MyActor.h"


AMyActor::AMyActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DesiredIntensity = 3000.0f;

	PointLight1 = ObjectInitializer.CreateDefaultSubobject<UPointLightComponent>(this, "PointLight1");
	PointLight1->Intensity = DesiredIntensity;
	PointLight1->bVisible = true;
	RootComponent = PointLight1;

	Sphere1 = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("Sphere1"));
	Sphere1->InitSphereRadius(250.0f);
	Sphere1->AttachParent = RootComponent;

	Sphere1->OnComponentBeginOverlap.AddDynamic(this, &AMyActor::OnOverlapBegin);        // set up a notification for when this component overlaps something
	Sphere1->OnComponentEndOverlap.AddDynamic(this, &AMyActor::OnOverlapEnd);      // set up a notification for when this component overlaps something
}

void AMyActor::OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

void AMyActor::OnOverlapEnd(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

void AMyActor::ToggleLight()
{
	PointLight1->ToggleVisibility();
}
