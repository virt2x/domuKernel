/******************************************************************************
 * tpmif.h
 *
 * TPM I/O interface for Xen guest OSes, v2
 *
 * This file is in the public domain.
 *
 */

#ifndef __XEN_PUBLIC_IO_TPMIF_H__
#define __XEN_PUBLIC_IO_TPMIF_H__

enum vtpm_shared_page_state {
       VTPM_STATE_IDLE,         /* no contents / vTPM idle / cancel complete */
       VTPM_STATE_SUBMIT,       /* request ready / vTPM working */
       VTPM_STATE_FINISH,       /* response ready / vTPM idle */
       VTPM_STATE_CANCEL,       /* cancel requested / vTPM working */
};
/* The backend should only change state to IDLE or FINISH, while the
 * frontend should only change to SUBMIT or CANCEL. */


struct vtpm_shared_page {
       uint32_t length;         /* request/response length in bytes */

       uint8_t state;           /* enum vtpm_shared_page_state */
       uint8_t locality;        /* for the current request */
       uint8_t pad;

       uint8_t nr_extra_pages;  /* extra pages for long packets; may be zero */
       uint32_t extra_pages[0]; /* grant IDs; length in nr_extra_pages */
};

#endif
