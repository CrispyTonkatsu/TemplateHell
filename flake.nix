{
  description = "A Nix-flake-based C/C++ development environment";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        devShells = {
          default =
            pkgs.mkShell.override
              {
                stdenv = pkgs.clang18Stdenv;
              }
              {
                packages = with pkgs; [
                  ninja
                  cmake
                  extra-cmake-modules
                  cmakeCurses
                  clang-tools
                ];
              };
        };
      }
    );
}
