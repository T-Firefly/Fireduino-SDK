OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)


/* Memory Spaces Definitions */
MEMORY
{
	rom (rwx)   : ORIGIN = 0x03000000, LENGTH = 0x00050000 /* Flash, 320K */
	ram (rwx)   : ORIGIN = 0x03050000, LENGTH = 0x00040000 /* sram, 256K */
}


BOOT_ROM_BASE   	=	0x00000000 ;
 
HRAM_CODE_BASE 		=	0x01000000 ;
HRAM_CODE_SIZE   	=	0x00020000 ;

HRAM_DATA_BASE   	=   0x01020000 ;
HRAM_DATA_SIZE   	=   0x00040000 ;

LOADER_DATA_BASE 	=   0x0304A000 ;
LOADER_CODE_BASE 	=   0x03088000 ;

SYS_DATA_BASE   	=	0x03000000 ;
SYS_DATA_SIZE    	=   (0x00050000) ;
SYS_DATA_LIMIT   	=   (0x03050000) ;

SYS_CODE_BASE     	=  	0x03050000 ;
SYS_CODE_SIZE     	=  	(0x00040000) ;
SYS_CODE_LIMIT   	=	(0x03090000) ;

DEV_CODE_START   	=   0x03070000 ;

PMU_DATA_BASE    	=   0x00000000 ;
PMU_DATA_SIZE     	=  	0x00001000 ;
PMU_CODE_BASE    	=   0x00001000 ;
PMU_CODE_SIZE   	=	0x0000F000 ;
SHELL_CODE_START 	=   0x0000C000 ;




/* Section Definitions */
SECTIONS
{
	.mode 0x3000000 - 0x12000 :  AT (0x3000000 - 0x12000)
	{
		_module_load_addr = .;
		KEEP(*(_ModuleInfo_ _ModuleInfo_.*))	
		_module_load_addr_end = .;	
	}
	
	OVERLAY SHELL_CODE_START : NOCROSSREFS  AT (0x3000000 - 0x10000)
	{
		.custom_shell
		{
			 _custom_shell_vma_ = ADDR(.custom_shell);
			 *(system_shell_shellcustomcmd_shell system_shell_shellcustomcmd_shell.*)	
			 *(system_shell_shellcustomcmd_shell_data system_shell_shellcustomcmd_shell_data.*)			
		}
		.dev_shell
		{
			 _dev_shell_vma_ = ADDR(.dev_shell);
			 *(system_shell_shelldevcmd_common system_shell_shelldevcmd_common.*)	
			 *(system_shell_shelldevcmd_shell_data system_shell_shelldevcmd_shell_data.*)			
		}
		.task_shell
		{
			 _task_shell_vma_ = ADDR(.task_shell);
			 *(system_shell_shelltaskcmd_common system_shell_shelltaskcmd_common.*)	
			 *(system_shell_shelltaskcmd_shell_data system_shell_shelltaskcmd_shell_data.*)			
		}
		.system_shell
		{
			 _system_shell_vma_ = ADDR(.system_shell);
			 *(system_shell_shellsyscmd_common system_shell_shellsyscmd_common.*)	
			 *(system_shell_shellsyscmd_shell_data system_shell_shellsyscmd_shell_data.*)			
		}
		.bcore_shell
		{
			 _bcore_shell_vma_ = ADDR(.bcore_shell);
			 *(driver_bcore_bcoredevice_shell driver_bcore_bcoredevice_shell.*)	
			 *(driver_bcore_bcoredevice_data driver_bcore_bcoredevice_data.*)			
		}
		.msg_shell
		{
			 _msg_shell_vma_ = ADDR(.msg_shell);
			 *(driver_msg_msgdevice_shell driver_msg_msgdevice_shell.*)	
			 *(driver_msg_msgdevice_shell_data driver_msg_msgdevice_shell_data.*)			
		}
		.rockcodec_shell
		{
			 _rockcodec_shell_vma_ = ADDR(.rockcodec_shell);
			 *(driver_rockcodec_rockcodecdevice_shell driver_rockcodec_rockcodecdevice_shell.*)	
			 *(driver_rockcodec_rockcodecdevice_shell_data driver_rockcodec_rockcodecdevice_shell_data.*)			
		}
		.i2c_shell
		{
			 _i2c_shell_vma_ = ADDR(.i2c_shell);
			 *(driver_i2c_i2cdevice_shell driver_i2c_i2cdevice_shell.*)	
			 *(driver_i2c_i2cdevice_data driver_i2c_i2cdevice_data.*)			
		}
		.i2s_shell
		{
			 _i2s_shell_vma_ = ADDR(.i2s_shell);
			 *(driver_i2s_i2sdevice_shell driver_i2s_i2sdevice_shell.*)	
			 *(driver_i2s_i2sdevice_shell_data driver_i2s_i2sdevice_shell_data.*)			
		}
		.audio_shell
		{
			 _audio_shell_vma_ = ADDR(.audio_shell);
			 *(driver_audio_audiodevice_shell driver_audio_audiodevice_shell.*)	
			 *(driver_audio_audiodevice_data driver_audio_audiodevice_data.*)			
		}			
		.dir_shell
		{
			 _dir_shell_vma_ = ADDR(.dir_shell);
			 *(driver_file_dirdevice_shell driver_file_dirdevice_shell.*)	
			 *(driver_file_dirdevice_data driver_file_dirdevice_data.*)			
		}
		.file_shell
		{
			 _file_shell_vma_ = ADDR(.file_shell);
			 *(driver_file_filedevice_shell driver_file_filedevice_shell.*)	
			 *(driver_file_filedevice_data driver_file_filedevice_data.*)			
		}
		.sd_shell
		{
			 _sd_shell_vma_ = ADDR(.sd_shell);
			 *(driver_sd_sddevice_shell driver_sd_sddevice_shell.*)	
			 *(driver_sd_sddevice_shell_data driver_sd_sddevice_shell_data.*)			
		}
		.sdc_shell
		{
			 _sdc_shell_vma_ = ADDR(.sdc_shell);
			 *(driver_sdmmc_sdmmcdevice_shell driver_sdmmc_sdmmcdevice_shell.*)	
			 *(driver_sdmmc_sdmmcdevice_shell_data driver_sdmmc_sdmmcdevice_shell_data.*)			
		}
		.sdio_shell
		{
			 _sdio_shell_vma_ = ADDR(.sdio_shell);
			 *(driver_sdio_sdiodevice_shell driver_sdio_sdiodevice_shell.*)	
			 *(driver_sdio_sdiodevice_shell_data driver_sdio_sdiodevice_shell_data.*)			
		}		
		.dma_shell
		{
			 _dma_shell_vma_ = ADDR(.dma_shell);
			 *(driver_dma_dmadevice_shell driver_dma_dmadevice_shell.*)	
			 *(driver_dma_dmadevice_data driver_dma_dmadevice_data.*)		
		}
		.fat_shell
		{
			 _par_shell_vma_ = ADDR(.fat_shell);
			 *(driver_volume_fatdevice_shell driver_volume_fatdevice_shell.*)	
			 *(driver_volume_fatdevice_shell_data driver_volume_fatdevice_shell_data.*)
		}  
		.par_shell
		{
			 _par_shell_vma_ = ADDR(.par_shell);
			 *(driver_partion_partiondevice_shell driver_partion_partiondevice_shell.*)	
			 *(driver_partion_partiondevice_shell_data driver_partion_partiondevice_shell_data.*)
		}  
		.lun_shell
		{
			 _lun_shell_vma_ = ADDR(.lun_shell);
			 *(driver_lun_lundevice_shell driver_lun_lundevice_shell.*)
			 *(driver_lun_lundevice_shell_data driver_lun_lundevice_shell_data.*)
					
		}
		.fifo_shell
		{
			 _fifo_shell_vma_ = ADDR(.fifo_shell);
			 *(driver_fifo_fifodevice_shell driver_fifo_fifodevice_shell.*)
			 *(driver_fifo_fifodevice_data driver_fifo_fifodevice_data.*)
					
		}		
		.uart_shell
		{
			 _uart_shell_vma_ = ADDR(.uart_shell);
			 *(driver_uart_uartdevie_shell driver_uart_uartdevie_shell.*)
			 *(driver_uart_uartdevice_shell_data driver_uart_uartdevice_shell_data.*)
					
		}
		.gpio_shell
		{
			 _gpio_shell_vma_ = ADDR(.gpio_shell);
			 *(cpu_nanod_lib_gpio_shell cpu_nanod_lib_gpio_shell.*)
			 *(cpu_nanod_lib_gpio_shell_data cpu_nanod_lib_gpio_shell_data.*)
					
		}
		.music_shell
		{
			 _music_shell_vma_ = ADDR(.music_shell);
			 *(app_audio_music_shell app_audio_music_shell.*)
			 *(app_audio_music_shell_data app_audio_music_shell_data.*)
					
		}
		.wifi_shell
		{
			 _wifi_shell_vma_ = ADDR(.wifi_shell);
			 *(ap6181wifiShell ap6181wifiShell.*)
			 *(ap6181wifiShell_data ap6181wifiShell_data.*)
					
		}

	} 
	_custom_shell_len_	= SIZEOF (.custom_shell);	
	_dev_shell_len_ 	= SIZEOF (.dev_shell);	
	_task_shell_len_ 	= SIZEOF (.task_shell);	
	_system_shell_len_ 	= SIZEOF (.system_shell);	
	_bcore_shell_len_ 	= SIZEOF (.bcore_shell);	
	_msg_shell_len_ 	= SIZEOF (.msg_shell);	
	_dir_shell_len_ 	= SIZEOF (.dir_shell);	
	_file_shell_len_ 	= SIZEOF (.file_shell);		
	_sd_shell_len_ 		= SIZEOF (.sd_shell);	
	_sdc_shell_len_ 	= SIZEOF (.sdc_shell);
	_sdio_shell_len_ 	= SIZEOF (.sdio_shell);	
	_dma_shell_len_ 	= SIZEOF (.dma_shell);	
	_fat_shell_len_		= SIZEOF (.fat_shell);	
	_par_shell_len_ 	= SIZEOF (.par_shell);	
	_lun_shell_len_ 	= SIZEOF (.lun_shell);
	_fifo_shell_len_ 	= SIZEOF (.fifo_shell);
	_uart_shell_len_ 	= SIZEOF (.uart_shell);
	_gpio_shell_len_ 	= SIZEOF (.gpio_shell);
	_music_shell_len_ 	= SIZEOF (.music_shell);
	_wifi_shell_len_ 	= SIZEOF (.wifi_shell);
	
    .text  : AT (0x3000000)
    {
        . = ALIGN(4);
        _sfixed = .;
        

		        
		_image_start_addr = .;
		/*KEEP(*(.vectors .vectors.*))*/
        KEEP(*(.interrupt_vector .interrupt_vector.*))
        *(.text .text.* .gnu.linkonce.t.*)
        *(.glue_7t) *(.glue_7)
        
        
        
        *(.rodata .rodata* .gnu.linkonce.r.*)
        *(.ARM.extab* .gnu.linkonce.armextab.*)

        /* Support C constructors, and C destructors in both user code
           and the C library. This also provides support for C++ code. */
        . = ALIGN(4);
        KEEP(*(.init))
        . = ALIGN(4);
        __preinit_array_start = .;
        KEEP (*(.preinit_array))
        __preinit_array_end = .;

        . = ALIGN(4);
        __init_array_start = .;
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array))
        __init_array_end = .;

        . = ALIGN(0x4);
        KEEP (*crtbegin.o(.ctors))
        KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors))
        KEEP (*(SORT(.ctors.*)))
        KEEP (*crtend.o(.ctors))

        . = ALIGN(4);
        KEEP(*(.fini))

        . = ALIGN(4);
        __fini_array_start = .;
        KEEP (*(.fini_array))
        KEEP (*(SORT(.fini_array.*)))
        __fini_array_end = .;

        KEEP (*crtbegin.o(.dtors))
        KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors))
        KEEP (*(SORT(.dtors.*)))
        KEEP (*crtend.o(.dtors))

        . = ALIGN(4);
        _efixed = .;            /* End of text section */
    } > rom

    /* .ARM.exidx is sorted, so has to go in its own output section.  */
    PROVIDE_HIDDEN (__exidx_start = .);
    .ARM.exidx :
    {
      *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > rom
    PROVIDE_HIDDEN (__exidx_end = .);



    . = ALIGN(4);
    _etext = .;
	_image_end_addr = .; 
	_image_end_leng = _image_end_addr - _image_start_addr; 



	
    .relocate : AT (_etext)
    {
        . = ALIGN(4);
        _srelocate = .;
		KEEP(*(ap_vect ap_vect*))
        *(.data .data.*);
        . = ALIGN(4);
        _erelocate = .;
		
		
    } > ram
	
	_relocate_len = _erelocate - _srelocate ;
	
    /* .bss section which is used for uninitialized data */
    .bss ALIGN(4) (NOLOAD) :
    {
        . = ALIGN(4);
        _sbss = . ;
		_bss_start = . ;
        *(.bss .bss.*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = . ;
    } > ram
	_bss_len = _ebss - _bss_start;


    /* .stack_dummy section doesn't contains any symbols. It is only
       used for linker to calculate size of stack sections, and assign
       values to stack symbols later */
    .stack_dummy ALIGN(4) (NOLOAD) :
    {
   		 _main_stack_start = .;
        KEEP(*(APMainStack))
        _main_stack_end = .;
    } > ram
    
 	. = ALIGN(8);
    _end = . ;
    _lm_heap_start = _end;
    _lm_heap_end = ORIGIN(ram) + LENGTH(ram);
    
    /*
    __StackTop = ORIGIN(ram) + LENGTH(ram);
    __StackLimit = __StackTop - SIZEOF(.stack_dummy);
    PROVIDE(_sstack = __StackLimit);
    PROVIDE(_estack = __StackTop);	
	*/

	OVERLAY _etext : NOCROSSREFS  AT (_etext + SIZEOF(.relocate))
	{
		.uart_init
		{
		 	_uart_init_vma_ = ADDR(.uart_init);
			*(driver_uart_uartdevie_init driver_uart_uartdevie_init.*)
		}
		.lun_init
		{
		 	_lun_init_vma_ = ADDR(.lun_init);	
		}
		.par_init
		{
		 	_par_init_vma_ = ADDR(.par_init);
			*(driver_partion_partiondevice_init driver_partion_partiondevice_init.*)
		}
		.fat_init
		{
		 	_fat_init_vma_ = ADDR(.fat_init);
			*(driver_volume_fatdevice_init driver_volume_fatdevice_init.*)
		}
		.dir_init
		{
		 	_dir_init_vma_ = ADDR(.dir_init);
			*(driver_file_dirdevice_init driver_file_dirdevice_init.*)
		}
		.file_init
		{
		 	_file_init_vma_ = ADDR(.file_init);
			*(driver_file_filedevice_init driver_file_filedevice_init.*)
		}
		.sd_init
		{
		 	_sd_init_vma_ = ADDR(.sd_init);
			*(driver_sd_sddevice_init driver_sd_sddevice_init.*)
		}
		.sdc_init
		{
		 	_sdc_init_vma_ = ADDR(.sdc_init);
			*(driver_sdmmc_sdmmcdevice_init driver_sdmmc_sdmmcdevice_init.*)
		}		
		

	} 
	. = ALIGN(4);
	_init_len = . - _etext;
	_uart_init_len_	= SIZEOF (.uart_init);	
	_lun_init_len_	= SIZEOF (.lun_init);
	_par_init_len_	= SIZEOF (.par_init);	
	_fat_init_len_	= SIZEOF (.fat_init);	
	_dir_init_len_	= SIZEOF (.dir_init);	
	_file_init_len_	= SIZEOF (.file_init);	
	
	_sd_init_len_	= SIZEOF (.sd_init);	
	_sdc_init_len_	= SIZEOF (.sdc_init);	
	
	OVERLAY HRAM_CODE_BASE : NOCROSSREFS  AT (__load_stop_sdc_init)
	{
		.bb_sys_code
		{
		 	_bb_sys_code_vma_ = ADDR(.bb_sys_code);
			KEEP(*(BBSysCode BBSysCode.*))
		}
		.sbc_decode_code
		{
		 	_sbc_decode_code_vma_ = ADDR(.sbc_decode_code);
			KEEP(*(SbcDecBinCode SbcDecBinCode.*))
		}
		.mp3_decode_code
		{
		 	_mp3_decode_code_vma_ = ADDR(.mp3_decode_code);
			KEEP(*(Mp3DecBinCode Mp3DecBinCode.*))
		}		
		.wma_decode_code
		{
		 	_wma_decode_code_vma_ = ADDR(.wma_decode_code);
			KEEP(*(WmaCommonBinCode WmaCommonBinCode.*))
		}	
		.wav_decode_code
		{
		 	_wav_decode_code_vma_ = ADDR(.wav_decode_code);
			KEEP(*(WavDecBinCode WavDecBinCode.*))
		}
		.flac_decode_code
		{
		 	_flac_decode_code_vma_ = ADDR(.flac_decode_code);
			KEEP(*(FlacDecBinCode FlacDecBinCode.*))
		}
		.aac_decode_code
		{
		 	_aac_decode_code_vma_ = ADDR(.aac_decode_code);
			KEEP(*(AacDecBinCode AacDecBinCode.*))
		}
		.ape_decode_code
		{
		 	_ape_decode_code_vma_ = ADDR(.ape_decode_code);
			KEEP(*(ApeDecBinCode ApeDecBinCode.*))		
		}
		.ogg_decode_code
		{
		 	_ogg_decode_code_vma_ = ADDR(.ogg_decode_code);
			KEEP(*(OggDecBinCode OggDecBinCode.*))		
		}	
		.flac_hdecode_code
		{
		 	_flac_hdecode_code_vma_ = ADDR(.flac_hdecode_code);
			KEEP(*(FlacHDecBinCode FlacHDecBinCode.*))		
		}
		.alac_hdecode_code
		{
		 	_alac_hdecode_code_vma_ = ADDR(.alac_hdecode_code);
			KEEP(*(AlacHDecBinCode AlacHDecBinCode.*))		
		}	
		.ape_hdecode_code
		{
		 	_ape_hdecode_code_vma_ = ADDR(.ape_hdecode_code);
			KEEP(*(ApeHDecBinCode ApeHDecBinCode.*))		
		}
		
	}
	_bb_sys_code_len_		= SIZEOF (.bb_sys_code);
	_sbc_decode_code_len_	= SIZEOF (.sbc_decode_code);	
	_mp3_decode_code_len_	= SIZEOF (.mp3_decode_code);	
	_wma_decode_code_len_	= SIZEOF (.wma_decode_code);	
	_wav_decode_code_len_	= SIZEOF (.wav_decode_code);	
	_flac_decode_code_len_	= SIZEOF (.flac_decode_code);	
	_aac_decode_code_len_	= SIZEOF (.aac_decode_code);
	_ape_decode_code_len_	= SIZEOF (.ape_decode_code);	
	_ogg_decode_code_len_	= SIZEOF (.ogg_decode_code);	
	_flac_hdecode_code_len_	= SIZEOF (.flac_hdecode_code);	
	_alac_hdecode_code_len_	= SIZEOF (.alac_hdecode_code);	
	_ape_hdecode_code_len_	= SIZEOF (.ape_hdecode_code);	
	
	
	OVERLAY HRAM_DATA_BASE : NOCROSSREFS  AT (__load_stop_ape_hdecode_code)
	{
		.bb_sys_data
		{
		 	_bb_sys_data_vma_ = ADDR(.bb_sys_data);
			KEEP(*(BBSysData BBSysData.*))
			KEEP(*(BBSysBss BBSysBss.*))
		}
		.sbc_decode_data
		{
		 	_sbc_decode_data_vma_ = ADDR(.sbc_decode_data);
			KEEP(*(SbcDecBinData SbcDecBinData.*))
			KEEP(*(SbcDecBinBss SbcDecBinBss.*))
		}
		.mp3_decode_data
		{
		 	_mp3_decode_data_vma_ = ADDR(.mp3_decode_data);
			KEEP(*(Mp3DecBinData Mp3DecBinData.*))
			KEEP(*(Mp3DecBinBss Mp3DecBinBss.*))
		}
		.wma_decode_data
		{
		 	_wma_decode_data_vma_ = ADDR(.wma_decode_data);
			KEEP(*(WmaCommonBinData WmaCommonBinData.*))
			KEEP(*(WmaCommonBinBss WmaCommonBinBss.*))
		}
		.wav_decode_data
		{
		 	_wav_decode_data_vma_ = ADDR(.wav_decode_data);
			KEEP(*(WavDecBinData WavDecBinData.*))
			KEEP(*(WavDecBinBss WavDecBinBss.*))
		}
		.flac_decode_data
		{
		 	_flac_decode_data_vma_ = ADDR(.flac_decode_data);
			KEEP(*(FlacDecBinData FlacDecBinData.*))
			KEEP(*(FlacDecBinBss FlacDecBinBss.*))
		}
		.aac_decode_data
		{
		 	_aac_decode_data_vma_ = ADDR(.aac_decode_data);
			KEEP(*(AacDecBinData AacDecBinData.*))
			KEEP(*(AacDecBinBss AacDecBinBss.*))
		}
		.ape_decode_data
		{
		 	_ape_decode_data_vma_ = ADDR(.ape_decode_data);
			KEEP(*(ApeDecBinData ApeDecBinData.*))
			KEEP(*(ApeDecBinBss ApeDecBinBss.*))		
		}
		.ogg_decode_data
		{
		 	_ogg_decode_data_vma_ = ADDR(.ogg_decode_data);
			KEEP(*(OggDecBinData OggDecBinData.*))
			KEEP(*(OggDecBinBss OggDecBinBss.*))		
		}
		.flac_hdecode_data
		{
		 	_flac_hdecode_data_vma_ = ADDR(.flac_hdecode_data);
			KEEP(*(FlacHDecBinData FlacHDecBinData.*))
			KEEP(*(FlacHDecBinBss FlacHDecBinBss.*))		
		}
		.alac_hdecode_data
		{
		 	_alac_hdecode_data_vma_ = ADDR(.alac_hdecode_data);
			KEEP(*(AlacHDecBinData AlacHDecBinData.*))
			KEEP(*(AlacHDecBinBss AlacHDecBinBss.*))		
		}					
		.ape_hdecode_data
		{
		 	_ape_hdecode_data_vma_ = ADDR(.ape_hdecode_data);
			KEEP(*(ApeHDecBinData ApeHDecBinData.*))
			KEEP(*(ApeHDecBinBss ApeHDecBinBss.*))		
		}	
		
	}
	
	_bb_sys_data_len_		= SIZEOF (.bb_sys_data);
	_sbc_decode_data_len_	= SIZEOF (.sbc_decode_data);	
	_mp3_decode_data_len_	= SIZEOF (.mp3_decode_data);	
	_wma_decode_data_len_	= SIZEOF (.wma_decode_data);	
	_wav_decode_data_len_	= SIZEOF (.wav_decode_data);	
	_flac_decode_data_len_	= SIZEOF (.flac_decode_data);	
	_aac_decode_data_len_	= SIZEOF (.aac_decode_data);
	_ape_decode_data_len_	= SIZEOF (.ape_decode_data);		
	_ogg_decode_data_len_	= SIZEOF (.ogg_decode_data);	
	_flac_hdecode_data_len_	= SIZEOF (.flac_hdecode_data);	
	_alac_hdecode_data_len_	= SIZEOF (.alac_hdecode_data);	
	_ape_hdecode_data_len_	= SIZEOF (.ape_hdecode_data);		

	OVERLAY HRAM_DATA_BASE : NOCROSSREFS  AT (__load_stop_ape_hdecode_data)
	{
		.wifi_fw
		{
		 	_wifi_fw_vma_ = ADDR(.wifi_fw);
			KEEP(*(_wifi_fw_ _wifi_fw_.*))
		}
		.wifi_nvram
		{
		 	_wifi_nvram_vma_ = ADDR(.wifi_nvram);
			KEEP(*(wifi_nvram wifi_nvram.*))
		}
	}
	_wifi_fw_len_	= SIZEOF (.wifi_fw);	
	_wifi_nvram_len_	= SIZEOF (.wifi_nvram);				
}
