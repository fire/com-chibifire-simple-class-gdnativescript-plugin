#pragma once

#include <godot.h>
#include <core/Godot.hpp>
#include <core/GodotGlobal.hpp>
#include <Reference.hpp>
#include <fbxsdk.h>

#include "EditorImportPlugin.hpp"

using godot::GodotScript;
using godot::register_class;
using godot::Reference;
using godot::Variant;
using godot::EditorImportPlugin;
using godot::String;
using godot::Reference;
using godot::Array;
using godot::Dictionary;

enum PrimitiveType {
	PRIMITIVE_POINTS = 0,
	PRIMITIVE_LINES = 1,
	PRIMITIVE_LINE_STRIP = 2,
	PRIMITIVE_LINE_LOOP = 3,
	PRIMITIVE_TRIANGLES = 4,
	PRIMITIVE_TRIANGLE_STRIP = 5,
	PRIMITIVE_TRIANGLE_FAN = 6,
	PRIMITIVE_MAX = 7,
};

enum ArrayType {
	ARRAY_VERTEX = 0,
	ARRAY_NORMAL = 1,
	ARRAY_TANGENT = 2,
	ARRAY_COLOR = 3,
	ARRAY_TEX_UV = 4,
	ARRAY_TEX_UV2 = 5,
	ARRAY_BONES = 6,
	ARRAY_WEIGHTS = 7,
	ARRAY_INDEX = 8,
	ARRAY_MAX = 9
};

class ResourceImporterFBX : public GodotScript<EditorImportPlugin> {
private:
	void InitializeSdkObjects(FbxManager *& pManager, FbxScene *& pScene);
	GODOT_CLASS(ResourceImporterFBX);
public:
	ResourceImporterFBX() { }
	
	String get_importer_name();
	String get_visible_name();
	int get_preset_count();
	String get_preset_name(const int preset);
	Array get_recognized_extensions();
	Array get_import_options(const int preset);
	String get_save_extension();
	String get_resource_type();
	bool get_option_visibility(const String option, const Dictionary options);
	int import(const String source_file, const String save_path, const Dictionary options, const Array r_platform_variants, const Array r_gen_files);

	static void _register_methods();
};

GODOT_NATIVE_INIT(godot_native_init_options *options) {
	register_class<ResourceImporterFBX>();
}

