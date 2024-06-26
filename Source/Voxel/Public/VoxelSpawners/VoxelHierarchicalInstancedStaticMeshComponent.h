// Copyright Voxel Plugin SAS. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VoxelMinimal.h"
#include "VoxelEnums.h"
#include "VoxelIntBox.h"
#include "VoxelSpawners/VoxelInstancedMeshSettings.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "VoxelHierarchicalInstancedStaticMeshComponent.generated.h"

struct FVoxelSpawnerTransform;
struct FVoxelSpawnerTransforms;
struct FVoxelHISMBuiltData;
struct FVoxelInstancedMeshAndActorSettings;
class IVoxelPool;
class FVoxelConstDataAccelerator;
class FVoxelInstancedMeshManager;

DECLARE_VOXEL_MEMORY_STAT(TEXT("Voxel HISM Memory"), STAT_VoxelHISMMemory, STATGROUP_VoxelMemory, VOXEL_API);

struct FVoxelInstancesSection
{
	int32 StartIndex = -1;
	int32 Num = -1;

	// Between 0 and Num - 1
	TSet<int32> RemovedIndices;
};

// Need to prefix names with Voxel to avoid collisions with normal HISM
UCLASS()
class VOXEL_API UVoxelHierarchicalInstancedStaticMeshComponent : public UHierarchicalInstancedStaticMeshComponent
{
	GENERATED_BODY()

public:
	// How long to wait for new instances before triggering a new cull tree/render update
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voxel")
	float Voxel_BuildDelay = 0.5f;

private:
	UPROPERTY()
	TObjectPtr<UMaterialInterface> Voxel_DebugMaterial;
		
public:
	UVoxelHierarchicalInstancedStaticMeshComponent(const FObjectInitializer& ObjectInitializer);
	~UVoxelHierarchicalInstancedStaticMeshComponent();
	
};

inline UVoxelHierarchicalInstancedStaticMeshComponent::UVoxelHierarchicalInstancedStaticMeshComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
inline UVoxelHierarchicalInstancedStaticMeshComponent::~UVoxelHierarchicalInstancedStaticMeshComponent()
{
}
