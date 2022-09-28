#pragma once

namespace VitDragonEngine{

	class Shader{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		static Shader* Create( const std::string& filePath );
		static Shader* Create( const std::string& vertexSrc, std::string& fragmentSrc );

	};

}