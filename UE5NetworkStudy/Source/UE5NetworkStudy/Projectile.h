// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class UE5NETWORKSTUDY_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	//이 발사체의 충돌 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USphereComponent* SphereComponent;

	//이 발사체의 메쉬 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* MeshComponent;

	//이 발사체의 이동 컴포넌트
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,CateGory = "Components")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	//이 발사체가 폭발할 때 사용할 이펙트
	UPROPERTY(EditAnywhere, Category = "Effects")
	class UParticleSystem* ExplosionEffect;

	//이 발사체가 가하는 데미지의 타입
	UPROPERTY(EditAnywhere, BlueprintReadOnly, CateGory = "Damage")
	TSubclassOf<UDamageType> DamageType;

	//이 발사체가 가하는 데미지
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	float Damage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
