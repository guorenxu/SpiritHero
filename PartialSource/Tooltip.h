// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

struct INDIEPROJECT_API Tooltip
{
public:
	FString Content;
	FLinearColor Color;

	Tooltip(FString content, FLinearColor color)
	{
		Content = content;
		Color = color;
	}
};
