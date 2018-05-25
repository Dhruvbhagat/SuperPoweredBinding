PROJECTNAME=SuperpoweredXCodeWrapper

TARGET=$(PROJECTNAME)
XBUILD=xcodebuild
XBUILD_FLAGS=-Wl,-map,output.map
PROJECT_ROOT=.
SOURCE=$(PROJECT_ROOT)/$(PROJECTNAME)
PROJECT=$(PROJECT_ROOT)/$(PROJECTNAME).xcodeproj
# You need to make sure that the SDK value below matches the SDK value in XCode under: Build Settings > Architectures > Base SDK.
SDK=iphoneos11.0
NAMESPACE=$(PROJECTNAME)

all: lib$(TARGET)SDK.a ApiDefinitions.cs StructsAndEnums.cs

lib$(TARGET)-i386.a:
	$(XBUILD) -project $(PROJECT) -target $(TARGET) -sdk iphonesimulator -arch x86_64 -configuration Release clean build
	-mv $(PROJECT_ROOT)/build/Release-iphonesimulator/lib$(TARGET).a $@

lib$(TARGET)-armv7.a:
	$(XBUILD) -project $(PROJECT) -target $(TARGET) -sdk iphoneos -arch armv7 -configuration Release clean build
	-mv $(PROJECT_ROOT)/build/Release-iphoneos/lib$(TARGET).a $@

lib$(TARGET)-arm64.a:
	$(XBUILD) -project $(PROJECT) -target $(TARGET) -sdk iphoneos -arch arm64 -configuration Release clean build
	-mv $(PROJECT_ROOT)/build/Release-iphoneos/lib$(TARGET).a $@

lib$(TARGET)SDK.a: lib$(TARGET)-i386.a lib$(TARGET)-armv7.a lib$(TARGET)-arm64.a
	xcrun -sdk iphoneos lipo -create -output $@ $^

ApiDefinitions.cs:
StructsAndEnums.cs:
	sharpie bind --output=$(PROJECT_ROOT) --namespace=$(NAMESPACE) --sdk=$(SDK) $(PROJECT_ROOT)/*.h

clean:
	-rm -rf *.a *.dll build ApiDefinitions.cs StructsAndEnums.cs

