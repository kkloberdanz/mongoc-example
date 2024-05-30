# Mongo C Driver Example

This is a small example project for the Mongo C Driver that pings the database
server.

## Dependencies

- A UNIX like system (Linux, MacOS, etc)
- A C compiler (gcc, clang, etc)
- pkg-config

## Build

Make sure you first setup pkg-config by exporting the `PKG_CONFIG_PATH`
variable to point to the directory where 'libmongoc-1.0.pc' is located.
For example, if you installed the C driver to `~/install`, you can set the
variable like so:

```sh
export PKG_CONFIG_PATH=$HOME/install/cdriver/lib/pkgconfig/
```

In order to run the program, make sure the linker can find the mongoc
libraries by setting `LD_LIBRARY_PATH`. If you installed the C driver to
`~/install`, then you can set the path like so:

Linux:
```sh
export LD_LIBRARY_PATH=$HOME/install/cdriver/lib
```

MacOS:
```sh
export DYLD_LIBRARY_PATH=$HOME/install/cdriver/lib
```

After doing this, you can build like so:
```sh
make
```

## Run

Make sure you have a MongoDB database running. Then run the `example` binary
like so.

```sh
./example
```

If successful, you will see the following message printed to your terminal:

```
Pinged your deployment. You successfully connected to MongoDB!
```
