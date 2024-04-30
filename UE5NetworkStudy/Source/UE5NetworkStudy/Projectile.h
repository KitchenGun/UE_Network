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

	//�� �߻�ü�� �浹 ������Ʈ
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USphereComponent* SphereComponent;

	//�� �߻�ü�� �޽� ������Ʈ
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* MeshComponent;

	//�� �߻�ü�� �̵� ������Ʈ
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,CateGory = "Components")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	//�� �߻�ü�� ������ �� ����� ����Ʈ
	UPROPERTY(EditAnywhere, Category = "Effects")
	class UParticleSystem* ExplosionEffect;

	//�� �߻�ü�� ���ϴ� �������� Ÿ��
	UPROPERTY(EditAnywhere, BlueprintReadOnly, CateGory = "Damage")
	TSubclassOf<UDamageType> DamageType;

	//�� �߻�ü�� ���ϴ� ������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	float Damage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
