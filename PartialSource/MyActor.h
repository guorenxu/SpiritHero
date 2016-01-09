

#pragma once

#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

/**
 * 
 */
UCLASS()
class INDIEPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	public:
	/** point light component */
	UPROPERTY(VisibleAnywhere, Category = "Switch Components")
	class UPointLightComponent* PointLight1;

	/** sphere component */
	UPROPERTY(VisibleAnywhere, Category = "Switch Components")
	class USphereComponent* Sphere1;

	AMyActor(const FObjectInitializer& ObjectInitializer);

	/** called when something enters the sphere component */
	UFUNCTION()
	void OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/** called when something leaves the sphere component */
	UFUNCTION()
	void OnOverlapEnd(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	/** Toggles the light component's visibility*/
	UFUNCTION()
	void ToggleLight();

	/** the desired intensity for the light */
	UPROPERTY(VisibleAnywhere, Category = "Switch Variables")
	float DesiredIntensity;
};
